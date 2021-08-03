#ifndef COMMON_H
#define COMMON_H

#include <cereal/archives/adapters.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/types/array.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/types/vector.hpp>
#include <fstream>
#include <iostream>
#include <memory>

// reading the structure and filling the file
template <typename POD>
void start_deserialization(POD& data, std::string file_name)
{
    std::ifstream ins(file_name);
    ins.open(file_name, std::ios::in);
    cereal::BinaryInputArchive archive(ins);
    archive(data);
    ins.close();
}

// reading a file and filling the structure
template <typename POD>

void start_serialization(POD& data, std::string file_name)
{
    std::ofstream out(file_name);
    out.open(file_name, std::ios::binary);
    cereal::BinaryOutputArchive archive(out);
    archive(data);
    out.close();
    data.display();
}

enum class h11_referenceFormatDR {

    H11_REFERENCE_FORMAT_DR_LAQ4 = 0,
    H11_REFERENCE_FORMAT_DR_LAQ8,
    H11_REFERENCE_FORMAT_DR_LOG4,
    H11_REFERENCE_FORMAT_DR_LOG8
};

enum class h11_referenceProjectorType {
    H11_REFERENCE_SPARSE = 0,
    H11_REFERENCE_SPARSE_LOW_POWER,
    H11_REFERENCE_DENSE,
    H11_REFERENCE_DENSE_LOW_POWER
};

enum class h11_calibProjDataType {

    H11_PROJ_DATA_TYPE_Sparse_PicToRef = 0,
    H11_PROJ_DATA_TYPE_Sparse_RefToPic,
    H11_PROJ_DATA_TYPE_Dense_PicToRef,
    H11_PROJ_DATA_TYPE_Dense_RefToPic,
};

enum class h11_referenceFormatPacked {
    H11_REFERENCE_FORMAT_PACKED_RAW = 0,
    H11_REFERENCE_FORMAT_PACKED_LZMA
};

#endif