#include "lzmacodec.h"
#include "lzma.h"

int lzma_encode(uint8_t* fdata, size_t fsize, u_int8_t** compressed_buffer, size_t* compressed_size)
{
    lzma_ret ret_xz;

    size_t maximum_size;
    maximum_size = lzma_stream_buffer_bound(fsize);

    *compressed_size = 0;
    *compressed_buffer = (uint8_t*)malloc(fsize);

    if (*compressed_buffer == NULL) {
        return 1;
    }

    lzma_options_lzma opt_lzma;
    lzma_lzma_preset(&opt_lzma, 1);
    opt_lzma.dict_size = 1024 * 3072;
    opt_lzma.lc = 4;
    opt_lzma.lp = 0;
    opt_lzma.pb = 3;
    opt_lzma.mode = LZMA_MODE_NORMAL;
    opt_lzma.mf = LZMA_MF_HC3;
    opt_lzma.nice_len = 273;
    opt_lzma.depth = 2;

    lzma_filter filters[LZMA_FILTERS_MAX + 1];
    filters[0].id = LZMA_FILTER_LZMA2;
    filters[0].options = &opt_lzma;
    filters[1].id = LZMA_VLI_UNKNOWN;

    ret_xz = lzma_stream_buffer_encode(filters, LZMA_CHECK_CRC32, NULL, fdata, fsize, *compressed_buffer, compressed_size, maximum_size);

    if (ret_xz != LZMA_OK) {
        if (*compressed_buffer != NULL) {
            free(*compressed_buffer);
            *compressed_buffer = NULL;
        }

        return 2;
    }

    return 0;
}

CODEC_RETURN compress(std::string src_raw_file, std::string trgt_cmpr_file)
{
    try {
        std::ifstream fr;
        fr.open(src_raw_file, std::ios::binary);
        fr.seekg(0, std::ios::end);
        size_t size = fr.tellg();
        char* str = new char[size];
        fr.seekg(0, fr.beg);
        fr.read(str, size);

        char* data = nullptr;
        size_t c_len = 0;

        // compress the file
        auto data_compressed = lzma_encode((uint8_t*)str, size, (u_int8_t**)&data, &c_len);

        std::ofstream fw;
        fw.open(trgt_cmpr_file, std::ios::binary);
        fw.write(data, c_len);
        delete[] str;

    } catch (std::ios_base::failure& e) {
        std::cerr << e.what() << '\n';
        return CODEC_RETURN::FAILED;
    }

    return CODEC_RETURN::SUCCESS;
}

CODEC_RETURN decompress(std::string src_cmp_file, std::string targ_raw_file)
{
    try {
        std::ifstream fr;
        fr.open(src_cmp_file, std::ios::binary);
        fr.seekg(0, std::ios::end);
        size_t size = fr.tellg();
        char* str = new char[size];
        fr.seekg(0, fr.beg);
        fr.read(str, size);

        // compress the file
        uint64_t memlimit = 0;

        memlimit = lzma_easy_decoder_memusage(3 | LZMA_PRESET_EXTREME);

        memlimit--;
        memlimit |= memlimit >> 1;
        memlimit |= memlimit >> 2;
        memlimit |= memlimit >> 4;
        memlimit |= memlimit >> 8;
        memlimit |= memlimit >> 16;
        memlimit++;

        // double that for safety's sake
        memlimit <<= 1;
        size_t src_pos = 0, dest_pos = 0;
        size_t blen = size * 20000; // trust compression is less than 2000%
        uint8_t* buf = new uint8_t[blen];

        auto retValue = lzma_stream_buffer_decode(&memlimit, 0, nullptr, (const uint8_t*)str, &src_pos, size, buf, &dest_pos, blen);
        if (retValue == LZMA_OK) {
            std::ofstream fw;
            fw.open(targ_raw_file, std::ios::binary);
            fw.write((char*)buf, dest_pos);
        } else {
            std::cout << "\nDecompression failed\n";
            return CODEC_RETURN::FAILED;
        }

        delete[] buf;
        delete[] str;

    } catch (std::ios_base::failure& e) {
        std::cerr << e.what() << '\n';
        return CODEC_RETURN::FAILED;
    }

    return CODEC_RETURN::SUCCESS;
}