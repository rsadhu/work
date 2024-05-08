cmake_minimum_required(VERSION 3.29)

project(test_boost)

message("CMAKE_MODULE_PATH---> ${CMAKE_MODULE_PATH}")

find_package(Boost REQUIRED COMPONENTS thread system)

add_executable(${PROJECT_NAME} main.cpp )

if (${Boost_FOUND})
    message(" its found")
elseif()
    message(" its not found")
endif()
message(" include paths are  ${Boost_INCLUDE_DIRS}")

include_directories(${Boost_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})  # Link Boost libraries
