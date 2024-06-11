# how to build
1.conan install . --build=missing --output=build
2.cmake ../ -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release