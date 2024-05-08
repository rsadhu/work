cmake_minimum_required(VERSION 3.10)
project(boost_http_server)

if(NOT DEFINED ${CMAKE_BUILD_TYPE})
    set(CMAKE_BUILD_TYPE "Debug")
endif()

message("build type is ..${CMAKE_BUILD_TYPE}")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")  # Add debug symbols
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")  # Add optimization
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(http_server main.cpp http_server.h)  # HTTP server source file

find_package(Boost REQUIRED COMPONENTS system thread)  # Find Boost libraries

find_package(OpenSSL REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(http_server ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES})  # Link Boost libraries
