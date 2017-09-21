// HRQs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
Sergey Bodrov 2012, serbod@gmail.com
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 102400
#define PKT_SIZE 188

/* pids */
#define PAT_PID                 0x0000
#define CAT_PID                 0x0001
#define TSDT_PID                0x0002
#define NIT_PID                 0x0010
#define SDT_PID                 0x0011

#define STREAM_TYPE_VIDEO_MPEG1     0x01
#define STREAM_TYPE_VIDEO_MPEG2     0x02
#define STREAM_TYPE_AUDIO_MPEG1     0x03
#define STREAM_TYPE_AUDIO_MPEG2     0x04
#define STREAM_TYPE_PRIVATE_SECTION 0x05
#define STREAM_TYPE_PRIVATE_DATA    0x06
#define STREAM_TYPE_AUDIO_AAC       0x0f
#define STREAM_TYPE_AUDIO_AAC_LATM  0x11
#define STREAM_TYPE_VIDEO_MPEG4     0x10
#define STREAM_TYPE_VIDEO_H264      0x1b
#define STREAM_TYPE_VIDEO_VC1       0xea
#define STREAM_TYPE_VIDEO_DIRAC     0xd1

#define STREAM_TYPE_AUDIO_AC3       0x81
#define STREAM_TYPE_AUDIO_DTS       0x8a

# define get_bit(val,bit) ((val & (1 << (bit))) >> (bit))

# define dump_flag(flag,text) if ( (flag) ) printf(" %s", (text))

static int _verbose = 1;

inline uint8_t get_8(uint8_t *buf, int *pos) {
	uint8_t tmp8;
	tmp8 = buf[*pos];
	*pos += 1;
	return tmp8;
}

inline uint16_t get_16(uint8_t *buf, int *pos) {
	uint16_t tmp16;
	tmp16 = buf[*pos + 1] + (buf[*pos] << 8);
	*pos += 2;
	return tmp16;

}

inline uint32_t get_32(uint8_t *buf, int *pos) {
	uint32_t tmp32;
	tmp32 = buf[*pos + 3] + (buf[*pos + 2] << 8) + (buf[*pos + 1] << 16) + (buf[*pos] << 24);
	*pos += 4;
	return tmp32;

}

inline char *get_str8(uint8_t *buf, int *pos) {
	int len;
	uint8_t tmp8;
	char *str;

	len = get_8(buf, pos);
	if (len < 0) return NULL;
	str = (char *)malloc(len + 1);
	if (!str) return NULL;
	memcpy(str, &buf[*pos], len);
	str[len] = '\0';
	*pos += len;
	return str;
}

void dump_bits16(uint16_t n) {
	int i;
	//printf("%u=",n);
	for (i = 15; i >= 0; i--) {
		printf("%u", ((n & (1 << i)) >> i));
		if ((i % 4) == 0) printf(" ");
	}
}

typedef struct {
	int pid;
	uint64_t last_pts;
	uint64_t last_dts;
} MpegTsPid;

// MPEG-TS transport packet
typedef struct {
	int len;            // 8 Number of bytes in the adaptation field immediately following this byte
	int discont;        // 1 Set to 1 if current TS packet is in a discontinuity state
	int random_access;  // 1 Set to 1 if the PES packet in this TS packet starts a video/audio sequence
	int es_prior;       // 1 higher priority)
	int pcr_flag;       // 1 adaptation field does contain a PCR field
	int opcr_flag;      // 1 adaptation field does contain an OPCR field
	int splice_flag;    // 1 splice countdown field in adaptation field
	int priv_flag;      // 1 private data bytes in adaptation field
	int ext_flag;       // 1 adaptation field extension
	uint64_t pcr;       // 33+6+9 Program clock reference (90 kHz base)
	int pcr_ext;        // PCR extension (27 MHz)
	uint64_t opcr;      // 33+6+9 Original Program clock reference. Helps when one TS is copied into another
	int opcr_ext;       // OPCR extension (27 MHz)
	int splice;         // 8 Indicates how many TS packets from this one a splicing point occurs (may be negative)
} MpegTsAdaptField;

typedef struct {
	int error_flag;     // 1  Transport Error Indicator
	int payload_flag;   // 1  Payload Unit Start Indicator
	int priority_flag;  // 1  Transport Priority
	int pid;            // 13 Packet ID
	int scramble;       // 2  Transport scrambling control (0,1,2,3)
	int adapt_field;    // 2  Adaptation field control (1,2,3)
	int cc;             // 4  Continuity counter
	MpegTsAdaptField af;
} MpegTsPacket;

// PSI (Program Specific Information) structures
/* SI (system information) section */
typedef struct {
	int skip_bytes;   // 8 skip bytes to payload
	int table_id;     // 8 table ID
	int syntax_flag;  // 1 section syntax indicator
	int pvt_flag;     // 1 private indicator
	// 2 reserved
	int len;          // 12 section length
	int len_pos;      // .. section length counts from this point
	// if (syntax_flag == 0), next private data .len-4 bytes
	// if syntax_flag == 1 then use next fields:
	int ext_id;       // 16 table ID extension
	// 2 reserved
	int version;      // 5 version number
	int next_flag;    // 1 current next indicator
	int num;          // 8 section number
	int last_num;     // 8 last section number
	// .. private data .len-9 bytes
} MpegTsSiHeader;

typedef struct {
	int tag;          // 8 descriptor tag
	int len;          // 8 descriptor data length in bytes
	uint8_t *data;    // raw data
} MpegTsDescriptor;

/* PAT (program association table */
typedef struct {
	int num;          // 16 program num
	// 3 reserved, '111'
	int pid;          // 13 packets with this PID are assumed to be PMT tables

} MpegTsPatRecord;

typedef struct {
	MpegTsSiHeader *h;
	// .h.table_id = 0x00
	// .h.section_syntax = 1
	// .h.ext_id = transport stream id

	int record_count;   //
	MpegTsPatRecord records[32];
} MpegTsPat;

/* PMT (program map table) */
typedef struct {
	int es_type;        // 08
	// 03 reserved '111'
	int es_pid;         // 13
	// 04 reserved
	int desc_len;    // 12 First two bits must be zero. Entire value may be zero
	int desc_count;     // 
	MpegTsDescriptor desc[8];
} MpegTsPmtRecord;

typedef struct {
	MpegTsSiHeader *h;
	// .h.table_id = 0x02
	// .h.section_syntax = 1
	// .h.ext_id = program num
	// ..
	// 03 reserved
	int pcr_pid;        // 13 PID of general timecode stream, or 0x1FFF
	// 4 reserved
	int info_len;       // 12 Sum size of following program descriptors.

	int record_count;   //
	MpegTsPmtRecord records[32];

} MpegTsPmt;

/* SDT (Service Description Table) */
typedef struct {
	int service_id;   // 16 service ID
	// 6 reserved
	int schedule;     // 1 EIT schedule flag
	int follow;       // 1 EIT present following flag
	int running_status; // 3 running status (1-stop, 2-starts, 3-pause, 4-running, 5-off-air)
	int free_ca_mode; // 1 free CA mode (0-not scrambled)
	int descr_len;    // 12 descriptor loop length
	int descr_count;  // descriptors count
	MpegTsDescriptor desc[8]; // descriptors 

} MpegTsSdtRecord;

#define MAX_SDT_SERVICES 16
typedef struct {
	MpegTsSiHeader *h;
	// .table_id = 0x42
	// .h.ext_id = transport stream id
	int orig_nw_id; // 16 original network id
	// 8 reserved
	// .. services
	int services_nb; // number of services
	MpegTsSdtRecord services[MAX_SDT_SERVICES];
} MpegTsSdt;

/* PES (Packetized Elementary Stream */
typedef struct {
	int stream_id;
	int len;            // Can be zero. If the PES packet length is set to zero, the PES packet can be of any length. A value of zero for the PES packet length can be used only when the PES packet payload is a video elementary stream.
	int scrambl;        // 00 implies not scrambled
	int prior_flag;
	int align_flag;     // 1 indicates that the PES packet header is immediately followed by the video start code or audio syncword
	int copyryght_flag; // 1 implies copyrighted
	int orig_flag;      // 1 implies original
	int pts_dts;        // 2 (11 = both present, 10 = only PTS
	int escr_flag;      // 1 ESCR flag
	int es_rate_flag;   // 1 ES rate flag
	int dsm_trick_mode_flag; // 1 DSM trick mode flag
	int add_copy_inf_flag;  // 1 Additional copy info flag
	int crc_flag;       // 1 CRC flag
	int ext_flag;       // 1 extension flag
	int data_len;       // 8 PES header data length
	// ..optional fields
	// Presentation Time Stamp / Decode Time Stamp
	uint64_t pts;       // 5b 001? 32..30 1 / 29..15 1 / 14..00 1
	uint64_t dts;       // 5b 00?1 32..30 1 / 29..15 1 / 14..00 1
	// Elementary Stream Clock Reference, used if the stream and system levels are not synchronized
	long int escr_base; // 6b 00 32..30 1 29..15 1 14..00 1 ext 1
	int escr_ext;
	// The rate at which data is delivered for this stream, in units of 50 bytes/second
	int es_rate;        // 16 1 es_rate 1
	int dsm_trick_mode;
	int add_copy_info;
	int prev_crc;       // 16 The polynomial used is X^16 + X^12 + X^5 + 1
} MpegTsPes;

typedef struct {
	uint8_t buf[MAX_BUFFER];
	int pos;
	int pids_count;
	MpegTsPid pids[32];       // stream pids from PAT/PMT
	MpegTsPid *cur_pid;       // current pid
	uint64_t last_pcr;
	MpegTsPacket *cur_pkt;    // current transport packet
} MpegTS;



static MpegTS ts;

char* get_pid_description(int pid) {
	switch (pid) {
	case PAT_PID: return "Program Association Table (PAT)";
	case CAT_PID: return "Conditional Access Table (CAT)";
	case TSDT_PID: return "Transport Stream Description (TSDT)";
	case NIT_PID: return "Network Information Table (NIT)";
	case SDT_PID: return "Service Description Table (SDT)";
	}
	return "";
}

char* get_pid_name(int pid) {
	switch (pid) {
	case 0x0000: return "PAT";
	case 0x0001: return "CAT";
	case 0x0010: return "NIT,ST";
	case 0x0011: return "SDT,BAT,ST";
	case 0x0012: return "EIT,ST_CIT";
	case 0x0013: return "RST,ST";
	case 0x0014: return "TDT,TOT,ST";
	case 0x0015: return "netwirk synchronization";
	case 0x0016: return "RNT";
	case 0x001c: return "inband signaling";
	case 0x001d: return "measurement";
	case 0x001e: return "DIT";
	case 0x001f: return "SIT";
	}
	return "";
}

char* get_table_id_name(int pid) {
	switch (pid) {
	case 0x00: return "program association";
	case 0x01: return "conditional access";
	case 0x02: return "program map";
	case 0x03: return "transport stream description";
		// 0x04 - 0x3f "reserved"
	case 0x40: return "actual network info";
	case 0x41: return "other network info";
	case 0x42: return "actual service description";
	case 0x46: return "other service description";
	case 0x4a: return "bouquet association";
	case 0x4e: return "actual event info now";
	case 0x4f: return "other event info now";
		// 0x50 - 0x5f "event info actual schedule"
		// 0x60 - 0x6f "event info other schedule"
	case 0x70: return "time data";
	case 0x71: return "running status";
	case 0x72: return "stuffing";
	case 0x73: return "time offset";
	case 0x74: return "application information";
	case 0x75: return "container";
	case 0x76: return "related content";
	case 0x77: return "content id";
	case 0x78: return "MPE-FEC";
	case 0x79: return "resolution notification";
	case 0x7a: return "MPE-IFEC";
		// 0x7b - 0x7d "reserved"
	case 0x7e: return "discontinuity info";
	case 0x7f: return "selection info";
		// 0x80 - 0xfe "user defined"
	case 0xff: return "reserved";
	}
	return "reserved";
}

char* get_stream_id_name(int stream_id) {
	switch (stream_id) {
	case 0x0000: return "reserved";
	case 0x0001: return "ISO/IEC 11172-2 (MPEG-1 Video)";
	case 0x0002: return "ISO/IEC 13818-2 (MPEG-2 Video)";
	case 0x0003: return "ISO/IEC 11172-3 (MPEG-1 Audio)";
	case 0x0004: return "ISO/IEC 13818-3 (MPEG-2 Audio)";
	case 0x0005: return "ISO/IEC 13818-1 (private section)";
	case 0x0006: return "ISO/IEC 13818-1 PES";
	case 0x0007: return "ISO/IEC 13522 MHEG";
	case 0x0008: return "ITU-T H.222.0 annex A DSM-CC";
	case 0x0009: return "ITU-T H.222.1";
	case 0x000a: return "ISO/IEC 13818-6 DSM-CC type A";
	case 0x000b: return "ISO/IEC 13818-6 DSM-CC type B";
	case 0x000c: return "ISO/IEC 13818-6 DSM-CC type C";
	case 0x000d: return "ISO/IEC 13818-6 DSM-CC type D";
	case 0x000e: return "ISO/IEC 13818-1 (auxiliary)";
	case 0x000f: return "ISO/IEC 13818-7 (AAC Audio)";
	case 0x0010: return "ISO/IEC 14496-2 (MPEG-4 Video)";
	case 0x0011: return "ISO/IEC 14496-3 (AAC LATM Audio)";
	case 0x001b: return "ITU-T H.264 (h264 Video)";
	case 0x00ea: return "(VC-1 Video)";
	case 0x00d1: return "(DIRAC Video)";
	case 0x0081: return "(AC3 Audio)";
	case 0x008a: return "(DTS Audio)";
	case 0x00bd: return "(non-MPEG Audio, subpictures)";
	case 0x00be: return "(padding stream)";
	case 0x00bf: return "(navigation data)";
		//case 0x001e: return "";
		//case 0x001f: return "";
	default: {
		if ((stream_id >= 0xc0) && (stream_id <= 0xdf)) return "(AUDIO stream)";
		else if ((stream_id >= 0xe0) && (stream_id <= 0xef)) return "(VIDEO stream)";

	}
	}
	return "";
}

int parse_descriptor(uint8_t *buf, int *pos, MpegTsDescriptor *desc) {
	char *tmp_str;
	uint8_t tmp8;

	desc->tag = get_8(buf, pos);
	desc->len = get_8(buf, pos);

	if (desc->tag == 0x48) { // service descriptor
		tmp8 = get_8(buf, pos);
		printf("    service type=0x%02x", tmp8);
		tmp_str = get_str8(buf, pos);
		printf(" author=\"%s\"", tmp_str);
		free(tmp_str);

		tmp_str = get_str8(buf, pos);
		printf(" info=\"%s\"\n", tmp_str);
		free(tmp_str);
		return 0;
	}
	else {
		printf("    descriptor tag=0x%02x length=%u \n", desc->tag, desc->len);
	}
	//desc->data = malloc(desc->len+1);
	//memcpy(desc->data, &buf[*pos], desc->len);
	*pos += desc->len;

	return 0;
}


int parse_si_header(uint8_t *buf, int *pos, MpegTsSiHeader *h) {
	uint8_t tmp8;
	uint16_t tmp16;
	h->skip_bytes = get_8(buf, pos);
	h->table_id = get_8(buf, pos); // must be 0x42
	tmp16 = get_16(buf, pos);
	h->syntax_flag = get_bit(tmp16, 15);
	h->len = tmp16 & 0x0fff; // 000 1111
	h->len_pos = *pos;
	if (h->syntax_flag) {
		h->ext_id = get_16(buf, pos);
		tmp8 = get_8(buf, pos);
		h->next_flag = get_bit(tmp8, 0);
		h->version = tmp8 & 0x3e >> 1; // 0011 1110
		h->num = get_8(buf, pos);
		h->last_num = get_8(buf, pos);
	}

	// dump SI header
	if (_verbose) {
		// dump header
		printf("  SI header: skip_bytes=%u table_id=%#02x length=%u", h->skip_bytes, h->table_id, h->len);
		dump_flag(h->syntax_flag, "syntax");
		if (h->syntax_flag) {
			printf(" ext_id=%u version=%u number=%u last_number=%u", h->ext_id, h->version, h->num, h->last_num);
			dump_flag(h->next_flag, "next");
		}
		printf("\n");
	}

	return 0;
}

void parse_pat(uint8_t *buf, int *pos, MpegTsSiHeader *h) {
	int i, i2, end_pos, sect_end;
	MpegTsPat pat_data;
	MpegTsPat *pat = &pat_data;
	uint16_t tmp16;
	MpegTsPatRecord *r;

	// non-verbose output
	if (!_verbose) {
		printf("pid=0x%04x [PAT]\n", ts.cur_pkt->pid);
	}
	pat->h = h;
	pat->record_count = 0;
	sect_end = pat->h->len_pos + pat->h->len - 4; // section length - CRC32
	while ((*pos < PKT_SIZE) && (*pos < sect_end)) {
		r = &pat->records[pat->record_count];
		pat->record_count++;

		r->num = get_16(buf, pos);
		tmp16 = get_16(buf, pos);
		r->pid = (tmp16 & 0x1fff); // 0001 1111

		// dump record info
		printf("  PAT program num=%u pmt_pid=0x%04x \n", r->num, r->pid);
	}

}

int parse_pmt(uint8_t *buf, int *pos, MpegTsSiHeader *h) {
	int start_pos = *pos;
	int i, i2, end_pos, sect_end;
	MpegTsPmtRecord *r;         // single table record
	MpegTsPmt t_data;           // table pointer
	MpegTsPmt *t = &t_data;   // table data
	uint8_t tmp8;
	uint16_t tmp16;

	t->record_count = 0;
	t->h = h;
	t->pcr_pid = get_16(buf, pos) & 0x1fff; // 0001 1111
	t->info_len = get_16(buf, pos) & 0x0fff; // 0000 1111

	// non-verbose output
	if (!_verbose) {
		printf("pid=0x%04x [PMT]\n", ts.cur_pkt->pid);
	}
	// dump header
	printf("  PMT pcr_pid=0x%04x", t->pcr_pid);
	if (t->info_len > 0) printf(" info_len=%u", t->info_len);
	printf("\n");

	sect_end = t->h->len_pos + t->h->len - 4; // section length - CRC32
	while ((*pos < PKT_SIZE) && (*pos < sect_end)) {
		// parse table record
		r = &t->records[t->record_count];
		t->record_count += 1;

		r->desc_count = 0;
		r->es_type = get_8(buf, pos);
		r->es_pid = get_16(buf, pos) & 0x1fff; // 0001 1111
		r->desc_len = get_16(buf, pos) & 0x0fff; // 0000 1111

		// add program PID to list
		i2 = 0;
		for (i = 0; i < ts.pids_count; i++) {
			if (ts.pids[i].pid == r->es_pid) i2 = 1; break;
		}
		if (i2 == 0) {
			ts.pids[ts.pids_count].pid = r->es_pid;
			ts.pids_count++;
		}

		// dump table record info
		printf("  PMT elementary stream type=0x%02x pid=0x%04x", r->es_type, r->es_pid);
		if (r->desc_len > 0) printf(" desc_len=%u", r->desc_len);
		printf("\n");
		printf("    %s\n", get_stream_id_name(r->es_type));

		if (r->desc_len <= (PKT_SIZE - *pos)) {

			// parse descriptors
			r->desc_count = 0;
			end_pos = *pos + r->desc_len;
			while (*pos < end_pos) {
				parse_descriptor(buf, pos, &r->desc[r->desc_count]);
				r->desc_count += 1;
			}
		}

	}
	return 0;
}

int parse_sdt(uint8_t *buf, int *pos, MpegTsSiHeader *h) {
	int start_pos = *pos;
	int i, i2, end_pos, sect_end;
	MpegTsSdtRecord *sv;
	MpegTsSdt sdt_data;
	MpegTsSdt *sdt = &sdt_data;
	uint8_t tmp8;
	uint16_t tmp16;

	sdt->h = h;
	sdt->orig_nw_id = get_16(buf, pos);
	tmp8 = get_8(buf, pos); // reserved field
	sdt->services_nb = 0;

	// non-verbose output
	if (!_verbose) {
		printf("pid=0x%04x [SDT]\n", ts.cur_pkt->pid);
	}
	// dump header
	printf("  SDT orig_network_id=0x%04x ", sdt->orig_nw_id);
	printf("\n");

	sect_end = sdt->h->len_pos + sdt->h->len - 4; // section length - CRC32
	while ((*pos < PKT_SIZE) && (*pos < sect_end)) {
		// parse service
		sdt->services_nb++;
		sv = &sdt->services[sdt->services_nb - 1];
		sv->service_id = get_16(buf, pos);
		tmp8 = get_8(buf, pos);
		sv->schedule = get_bit(tmp8, 1);
		sv->follow = get_bit(tmp8, 0);

		tmp16 = get_16(buf, pos);
		sv->running_status = (tmp16 & 0x7000) >> 13; // 1110 0000
		sv->free_ca_mode = get_bit(tmp16, 12);
		sv->descr_len = tmp16 & 0x0fff; // 0000 1111

		// dump service info
		printf("  SDT service_id=0x%04x running=%u descr_len=%u", sv->service_id, sv->running_status, sv->descr_len);
		dump_flag(sv->schedule, "schedule");
		dump_flag(sv->follow, "follow");
		dump_flag(sv->free_ca_mode, "free_ca_mode");
		printf("\n");

		if (sv->descr_len <= (PKT_SIZE - *pos)) {

			// parse descriptors
			sv->descr_count = 0;
			end_pos = *pos + sv->descr_len;
			while (*pos < end_pos) {
				parse_descriptor(buf, pos, &sv->desc[sv->descr_count]);
				sv->descr_count++;
			}
		}

	}
	return 0;
}

uint64_t parse_pes_pts(uint8_t *buf, int *pos) {
	uint64_t tmp64;
	uint16_t tmp16;
	uint8_t tmp8;

	tmp8 = get_8(buf, pos);
	tmp64 = ((int64_t)tmp8 >> 1) & 0x07 << 30;
	tmp16 = get_16(buf, pos);
	tmp64 |= ((int64_t)tmp16 >> 1) << 15;
	tmp16 = get_16(buf, pos);
	tmp64 |= ((int64_t)tmp16 >> 1);

	return tmp64;
}


int parse_pes(uint8_t *buf, int *pos) {
	// PES
	uint16_t tmp16;
	uint8_t tmp8;
	MpegTsPes pes_data;
	MpegTsPes *pes = &pes_data;
	MpegTsPid *pid;
	int ii, payload_pos;

	// check for PES header
	// Packet start code prefix 3 bytes	0x000001
	tmp16 = get_16(buf, pos);
	tmp8 = get_8(buf, pos);
	if ((tmp16 == 0 && tmp8 == 1) != 1) {
		// it's not PES, rewind pos backward
		*pos -= 3;
		return -1;
	}
	// PES detected
	tmp8 = get_8(buf, pos);
	pes->stream_id = tmp8;

	pes->len = get_16(buf, pos);;

	// dump PES header
	if (_verbose) {
		printf("  PES stream_id=%#x length=%u  ", pes->stream_id, pes->len);
		printf("  %s", get_stream_id_name(pes->stream_id));
		printf("\n");
	}
	// non-verbose output
	if (!_verbose) {
		printf("pid=0x%04x [PES] %s\n", ts.cur_pkt->pid, get_stream_id_name(pes->stream_id));
		// PCR
		if (ts.cur_pkt->adapt_field) {
			if (ts.cur_pkt->af.pcr_flag) {
				printf("  PCR=%llu (%+lli)", ts.cur_pkt->af.pcr, (ts.cur_pkt->af.pcr - ts.last_pcr));
				if (ts.cur_pkt->af.pcr_ext != 0) printf(" pcr_ext=%u", ts.cur_pkt->af.pcr_ext);
				printf("\n");
			}
		}
	}

	// optional header
	tmp8 = get_8(buf, pos);
	ii = (tmp8 & 0xc0) >> 6; //1100 0000;
	if (ii == 2) {  // bin '10'
		pes->scrambl = (tmp8 & 0x30) >> 4; // 0011 0000
		pes->prior_flag = get_bit(tmp8, 3);
		pes->align_flag = get_bit(tmp8, 2);
		pes->copyryght_flag = get_bit(tmp8, 1);
		pes->orig_flag = get_bit(tmp8, 0);

		tmp8 = get_8(buf, pos);
		pes->pts_dts = (tmp8 & 0xc0) >> 6; //1100 0000
		pes->escr_flag = get_bit(tmp8, 5);
		pes->es_rate_flag = get_bit(tmp8, 4);
		pes->dsm_trick_mode_flag = get_bit(tmp8, 3);
		pes->add_copy_inf_flag = get_bit(tmp8, 2);
		pes->crc_flag = get_bit(tmp8, 1);
		pes->ext_flag = get_bit(tmp8, 0);
		pes->data_len = get_8(buf, pos);
		payload_pos = *pos + pes->data_len;

		// dump optional header
		if (_verbose) {
			printf("  PES flags:");
			dump_flag((pes->scrambl), "scramble");
			dump_flag((pes->pts_dts >> 1), "pts");
			dump_flag((pes->pts_dts & 0x01), "dts");
			dump_flag(pes->prior_flag, "priority");
			dump_flag(pes->align_flag, "align");
			dump_flag(pes->copyryght_flag, "(c)");
			dump_flag(pes->orig_flag, "original");
			dump_flag(pes->escr_flag, "ESCR");
			dump_flag(pes->es_rate_flag, "ES_rate");
			dump_flag(pes->dsm_trick_mode_flag, "DSM_trick_mode");
			dump_flag(pes->add_copy_inf_flag, "add_copy_inf");
			dump_flag(pes->crc_flag, "CRC");
			dump_flag(pes->ext_flag, "ext");
			printf("\n");
		}

		pes->pts = pes->dts = 0;

		if (pes->pts_dts > 1) { // PTS
			pes->pts = parse_pes_pts(buf, pos);
			if (_verbose) printf("  PES PTS=%llu", pes->pts);
			if (!_verbose) printf("  PTS=%llu", pes->pts);

			if (ts.cur_pid != NULL) {
				printf(" (%+lli)", (pes->pts - ts.cur_pid->last_pts));
				ts.cur_pid->last_pts = pes->pts;
			}
			if (!_verbose) printf("\n");

			if (pes->pts_dts == 3) { // DTS
				pes->dts = parse_pes_pts(buf, pos);
				if (_verbose) printf(" DTS=%llu", pes->dts);
				if (!_verbose) printf("  DTS=%llu", pes->dts);
				if (ts.cur_pid != NULL) {
					printf(" (%+lli)", (pes->dts - ts.cur_pid->last_dts));
					ts.cur_pid->last_dts = pes->dts;
				}
				if (!_verbose) printf("\n");
			}
			if (_verbose) printf("\n");
		}

		// other PES header data
		//...

		// skip to payload
		*pos = payload_pos;
	}

	// PES payload
	if (*pos + 4 <= PKT_SIZE) {
		// dump payload header 4cc
		if (_verbose) {
			printf("  PES payload 0x%08x", get_32(buf, pos));
			if (*pos + 4 <= PKT_SIZE) {
				// dump second 4cc 
				printf(" 0x%08x", get_32(buf, pos));
			}
			printf("\n");
		}
	}


	return 0;
}

// PCR field value
uint64_t parse_pcr(uint8_t *buf, int *pos, int *ext) {
	// 33 base
	// 06 reserved
	// 09 extension
	uint64_t tmp64 = 0;
	uint8_t tmp8 = 0;

	int i;
	for (i = 0; i<4; i++) {
		tmp64 |= get_8(buf, pos) << (8 * (3 - i));
	}
	tmp8 = get_8(buf, pos);
	tmp64 = (tmp64 << 1) | get_bit(tmp8, 7);

	*ext = (get_bit(tmp8, 0) << 8) | get_8(buf, pos);
	return tmp64;
}

int parse_pkt(uint8_t *buf, MpegTsPacket *pkt) {
	int pos_value = 0;
	int *pos = &pos_value;
	int i, ii;
	uint16_t tmp16;
	uint8_t tmp8;
	MpegTsAdaptField *af = &pkt->af;
	MpegTsSiHeader sih;

	if (buf[*pos] != 0x47) return -1;
	ts.cur_pkt = pkt;
	*pos += 1;
	tmp16 = get_16(buf, pos);
	// dump_16(tmp16); printf(" \n");
	pkt->error_flag = get_bit(tmp16, 15);
	pkt->payload_flag = get_bit(tmp16, 14);
	pkt->priority_flag = get_bit(tmp16, 13);
	pkt->pid = tmp16 & 0x1fff; // 0x1f = 0001 1111
	tmp8 = get_8(buf, pos);
	pkt->scramble = (tmp8 & 0xc0) >> 6; // 0xc0 = 1100 0000
	pkt->adapt_field = (tmp8 & 0x30) >> 4; // 0x30 = 0011 0000
	pkt->cc = tmp8 & 0x0f; // 0000 1111

	// dump packet
	if (_verbose) {
		printf("pid=0x%04x cc=%u", pkt->pid, pkt->cc);
		dump_flag(pkt->error_flag, "error");
		dump_flag(pkt->payload_flag, "PES/SI");
		dump_flag(pkt->priority_flag, "priority");
		dump_flag(pkt->scramble, "scramble");
		dump_flag(pkt->adapt_field > 1, "adapt");
		dump_flag(pkt->adapt_field & 1, "payload");
		printf("    %s", get_pid_description(pkt->pid));
		printf("\n");
	}

	// adaptation field (optional)
	if (pkt->adapt_field > 1) {
		af->len = get_8(buf, pos);

		tmp8 = get_8(buf, pos);
		af->discont = (tmp8 & (1 << 7)) >> 7;
		af->random_access = (tmp8 & (1 << 6)) >> 6;
		af->es_prior = (tmp8 & (1 << 5)) >> 5;
		af->pcr_flag = (tmp8 & (1 << 4)) >> 4;
		af->opcr_flag = (tmp8 & (1 << 3)) >> 3;
		af->splice_flag = (tmp8 & (1 << 2)) >> 2;
		af->priv_flag = (tmp8 & (1 << 1)) >> 1;
		af->ext_flag = (tmp8 & (1 << 0)) >> 0;

		// dump adaptation field
		if (_verbose) {
			printf("  adapt_field length=%u", af->len);
			dump_flag(af->discont, "discontinuity");
			dump_flag(af->random_access, "random_access");
			dump_flag(af->es_prior, "es_priority");
			//dump_flag(af->pcr_flag, "PCR");
			//dump_flag(af->opcr_flag, "OPCR");
			//dump_flag(af->splice_flag, "splice");
			dump_flag(af->priv_flag, "private");
			dump_flag(af->ext_flag, "extension");
		}

		// optional header data
		if (af->pcr_flag) {
			ts.last_pcr = af->pcr;
			af->pcr = parse_pcr(buf, pos, &(af->pcr_ext));
			if (_verbose) {
				printf(" PCR=%llu (%+lli)", af->pcr, (af->pcr - ts.last_pcr));
				if (af->pcr_ext != 0) printf(" pcr_ext=%u", af->pcr_ext);
			}
		}
		if (af->opcr_flag) {
			af->opcr = parse_pcr(buf, pos, &(af->opcr_ext));
			if (_verbose) {
				printf(" OPCR=%llu", af->pcr);
				if (af->opcr_ext != 0) printf(" opcr_ext=%u", af->opcr_ext);
			}
		}
		if (af->splice_flag) {
			af->splice = get_8(buf, pos);
			if (_verbose) printf(" splice_count=%i", af->splice);
		}

		if (_verbose) printf("\n");

		*pos = 4 + 1 + af->len; // skip after adaptation field

	}

	ts.cur_pid = NULL;
	if (pkt->payload_flag) {
		// packet have payload section

		// look for PID in PAT table
		for (i = 0; i<ts.pids_count; i++) {
			if (ts.pids[i].pid == pkt->pid) {
				ts.cur_pid = &ts.pids[i];
				// detect PES header
				if (parse_pes(buf, pos) == 0) return 0;
			}
		}
		if (pkt->pid > 0x20) {
			if (parse_pes(buf, pos) == 0) return 0;
		}

		tmp8 = buf[*pos + 1]; // table_id
		if (_verbose) printf("  service table name: %s\n", get_table_id_name(tmp8));

		parse_si_header(buf, pos, &sih);

		switch (pkt->pid) {
		case 0x0000: parse_pat(buf, pos, &sih); break; // PAT table
		case 0x0011: parse_sdt(buf, pos, &sih); break; // SDT table
		default: {
			// other packets
			if (tmp8 == 0x02) { // PMT table
				parse_pmt(buf, pos, &sih);
				return 0;
			}

			if (pkt->payload_flag) {
				// unknown payload
				tmp16 = get_16(buf, pos);
				if (_verbose) {
					printf("  payload header=0x%02x  ", tmp16);
					dump_bits16(tmp16);
					printf("\n");
				}
			}
		}
		}
	}

	return 0;
}

void do_some() {
	int ir, i, pos47;
	MpegTsPacket pkt;
	uint8_t pkt_buf[PKT_SIZE];

	ts.last_pcr = 0;
	ts.pids_count = 0;
	FILE *fp = 0;
 fopen_s(&fp, "D:\\rsadhu\\codingPractice\\work_git\\2017\\AllInOne\\elephants.ts", "r");
	if (fp)
	{
		ir = fread(ts.buf, 1, MAX_BUFFER, fp);
		//if (ir != MAX_BUFFER) return -1;
		for (i = 0; i < ir; i++) {
			if (ts.buf[i] == 0x47) {
				pos47 = i;
				memcpy(&pkt_buf, &ts.buf[i], sizeof(pkt_buf));
				i += sizeof(pkt_buf) - 1;
				parse_pkt(&pkt_buf[0], &pkt);

				fflush(stdout);

			}
		}
	}
}


int main(int argc, char**argv) {
	if (argc > 1) {
		if ((strcmp(argv[1], "--help") == 0) || (strcmp(argv[1], "-h") == 0)) {
			printf("  Usage: %s [-b] < input.ts > output.log\n", argv[0]);
			printf("Options:\n");
			printf("    -b - brief mode\n");
			return 0;
		}
		if (strcmp(argv[1], "-b") == 0) {
			_verbose = 0;
		}
	}
	do_some();
	return 0;
}
