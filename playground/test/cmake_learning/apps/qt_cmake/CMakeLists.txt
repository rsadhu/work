cmake_minimum_required(VERSION 3.29)

project(test_qt)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME} main.cpp )

if (${Qt5_FOUND})
    message(" its found")
elseif()
    message(" its not found")
endif()
message(" include paths are  ${Qt5_INCLUDE_DIRS}")

include_directories(${Qt5_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)  # Link Boost libraries
