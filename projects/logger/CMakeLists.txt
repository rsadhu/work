cmake_minimum_required(VERSION 3.0)
project(Logger)


# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SPDLOG REQUIRED)
# Define your project


#include_directories(${PROJECT_NAME} ${SPDLOG_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} src/main.cpp src/logger.cpp)

target_link_libraries(${PROJECT_NAME} spdlog::spdlog)
