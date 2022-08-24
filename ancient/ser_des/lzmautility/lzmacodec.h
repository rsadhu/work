#pragma once
#ifndef LZMACODEC_H
#define LZMACODEC_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

enum class CODEC_RETURN
{
    FAILED,
    SUCCESS
};

CODEC_RETURN compress(std::string src_raw_file, std::string trgt_cmpr_file);
CODEC_RETURN decompress(std::string src_cmp_file, std::string src_raw_file);

#endif
