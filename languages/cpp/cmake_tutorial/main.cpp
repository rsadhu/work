#include <iostream>
#include <zlib.h>

#include "test.pb.h"

using namespace cmake;

void zipper()
{
        char buffer_in [256] = {"Conan is a MIT-licensed, Open Source package manager for C and C++ development "
                            "for C and C++ development, allowing development teams to easily and efficiently "
                            "manage their packages and dependencies across platforms and build systems."};
    char buffer_out [256] = {0};

    z_stream defstream;
    defstream.zalloc = Z_NULL;
    defstream.zfree = Z_NULL;
    defstream.opaque = Z_NULL;
    defstream.avail_in = (uInt) strlen(buffer_in);
    defstream.next_in = (Bytef *) buffer_in;
    defstream.avail_out = (uInt) sizeof(buffer_out);
    defstream.next_out = (Bytef *) buffer_out;

    deflateInit(&defstream, Z_BEST_COMPRESSION);
    deflate(&defstream, Z_FINISH);
    deflateEnd(&defstream);

    printf("Uncompressed size is: %lu\n", strlen(buffer_in));
    printf("Compressed size is: %lu\n", strlen(buffer_out));

    printf("ZLIB VERSION: %s\n", zlibVersion());
}

int main(void)
{
    cmake_test c;
    c.set_project_name("test");
    c.add_source_files("main.cpp");
    c.add_source_files("test.cpp");
    c.set_id(27);
    c.mutable_lib()->set_libname("learning stuff");
    c.mutable_lib()->set_version(1982);

    std::string msg = c.SerializeAsString();
    std::cout<<msg<<"\n";

    zipper();

    return 0;
}