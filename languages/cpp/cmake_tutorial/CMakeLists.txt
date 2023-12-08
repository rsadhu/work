project("cmakepro")
cmake_minimum_required(VERSION 3.21.3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#find_package(ZLIB REQUIRED)
#find_library(ZLIB libz.a)

add_executable(${PROJECT_NAME} main.cpp test.pb.cc)
target_link_libraries(${PROJECT_NAME} protobuf ZLIB::ZLIB)