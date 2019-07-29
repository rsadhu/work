cmake_minimum_required (VERSION 2.6)
PROJECT(training)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set (QT_QMAKE_EXECUTABLE "/home/rsadhu/Qt/5.12.3/gcc_64/bin/qmake")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(dsa)
add_subdirectory(cpp-11-17-features)


