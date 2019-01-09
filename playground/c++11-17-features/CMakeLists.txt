cmake_minimum_required(VERSION 2.9)
project(cppfeatures)

#set the name of executable
set(executablename  "cppfeatures") 


set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



add_executable(${executablename} cppfeatures.cpp main.cpp)



#message("CMAKE_BINARY_DIR      "${CMAKE_BINARY_DIR})
#message("CMAKE_SOURCE_DIR      "${CMAKE_SOURCE_DIR})
#message("CMAKE_CURRENT_BINARY_DIR      "${CMAKE_CURRENT_BINARY_DIR})


