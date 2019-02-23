cmake_minimum_required(VERSION 2.9)
project(cppfeatures)

set(executablename  "cppfeatures") 

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE HEADERS *.h)
file(GLOB_RECURSE SOURCES *.cpp)

SOURCE_GROUP("src" FILES ${SOURCES})
SOURCE_GROUP("hdr" FILES ${HEADERS})

add_executable(${executablename} ${SOURCES})
