#include "lzmacodec.h"

void right_arg_list()
{
    std::cout << "./lzmautility --compress source_file_with_path target_file_with_path\n";
    std::cout << "./lzmautility --decompress source_file_with_path target_file_with_path\n";
}

int main(int argc, char* argv[])
{

    if (argc != 4) {
        std::cout << "Insufficient/Wrong number of Args passed\n";
        right_arg_list();
        return -1;
    }

    std::string operation = argv[1];
    std::string src_file = argv[2];
    std::string tar_file = argv[3];

    if (operation == "--compress") {
        std::cout << "\ncompression starts\n";
        auto res = compress(src_file, tar_file);
        if (res == CODEC_RETURN::SUCCESS) {
            std::cout << " Compression is successful\n";
        } else {
            std::cout << " Compression is Failed\n";
        }
    } else if (operation == "--decompress") {
        std::cout << "\ndecompression starts\n";
        //auto res = decompress("/Users/rsadhu/dev/apples/lzmautility/build/test_data_compressed.bin", "/Users/rsadhu/dev/apples/lzmautility/build/test_data_uncompressed_1.bin");
        auto res = decompress(src_file, tar_file);
        if (res == CODEC_RETURN::SUCCESS) {
            std::cout << " DeCompression is successful\n";
        } else {
            std::cout << " DeCompression is Failed\n";
        }
    } else {
        std::cout << "\n Wrong operation choosen , please try again\n";
        right_arg_list();
    }
    return 0;
}
