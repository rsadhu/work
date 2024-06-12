cmake_minimum_required(VERSION 3.10)
project(CircleAnimation)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(CircleAnimation main.cpp graphicsview.cpp graphicsview.h)

target_link_libraries(CircleAnimation Qt6::Widgets)
