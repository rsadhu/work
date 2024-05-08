# Minimum CMake version
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(HttpServer VERSION 1.0)

# Find Boost libraries
find_package(Boost 1.65 REQUIRED COMPONENTS system)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    main.cpp  # Your main source file
)

# Include directories (if necessary)
include_directories(${Boost_INCLUDE_DIRS})

# Add the executable
add_executable(HttpServer ${SOURCES})

# Link Boost libraries to the executable
target_link_libraries(HttpServer ${Boost_LIBRARIES})
