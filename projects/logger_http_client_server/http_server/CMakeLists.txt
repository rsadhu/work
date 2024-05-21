cmake_minimum_required(VERSION 3.10)
project(BoostHttpServer)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system thread)

add_executable(http_server main.cpp)
target_include_directories(http_server PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(http_server PRIVATE ${Boost_LIBRARIES})
