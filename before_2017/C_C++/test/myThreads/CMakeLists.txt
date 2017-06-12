cmake_minimum_required (VERSION 2.8.11)
project (Thread C CXX)
add_executable (Thread Thread.cpp Thread_P.cpp main.cpp)
target_link_libraries (Thread pthread)
