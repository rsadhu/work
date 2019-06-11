cmake_minimum_required (VERSION 2.6)
PROJECT(training)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dsa)
add_subdirectory(cpp-11-17-features)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")


#file(GLOB SOURCES *.cpp)
#file(GLOB HEADERS *.h)

#source_group("Headers" FILES ${HEADERS})
#source_group("Headers" FILES ${SOURCES})
