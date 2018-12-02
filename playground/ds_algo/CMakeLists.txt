cmake_minimum_required(VERSION 3.1)
project(Playground)

set (CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(HEADERS Vector/Vector.h
            Recursion/RecursionUtility.h)

SET(SOURCES Recursion/RecursionUtility.cpp main.cpp)


if( BUILDTYPE STREQUAL "DEBUG" )
   Message("Debug Build") 
endif()


#add_executable(Playground ${HEADERS} ${SOURCES})

add_library(Playground SHARED ${SOURCES})

set(dest "/home/rsadhu/work/playground/ds_algo/build")

install(TARGETS  Playground DESTINATION ${dest})


