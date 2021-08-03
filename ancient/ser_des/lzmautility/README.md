# lzmautility
utility to compress and decompress data files

# Usage

Usage from Matlab call Functor as follows:

For compression
arr{1} = "/Users/rsadhu/dev/apples/lzmautility/test_data_raw.bin";
arr{2} = "/Users/rsadhu/dev/apples/lzmautility/test_data_comppresss_.zip";
arr{3} = "compress";

matlab_codec(arr)

For decompression

arr{1} = "/Users/rsadhu/dev/apples/lzmautility/test_data_comppresss_.zip";
arr{2} = "/Users/rsadhu/dev/apples/lzmautility/test_data_raw.bin";
arr{3} = "compress";

matlab_codec(arr)

