cmake_minimum_required(VERSION 3.29)
project(custom_boost_lib)

find_package(Boost REQUIRED)

add_library(${PROJECT_NAME} SHARED http_server.cpp http_server.h)

include_directories(${PROJECT_NAME} ${Boost_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
