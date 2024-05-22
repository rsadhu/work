cmake_minimum_required(VERSION 3.15)
project(my_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SPDLOG REQUIRED)
# Add the main executable


message("${SPDLOG_INCLUDE_DIRS}")
include_directories(${PROJECT_NAME} ${SPDLOG_INCLUDE_DIRS})
add_executable(my_project src/main.cpp)

# Link the spdlog library
target_link_libraries(my_project SPDLOG)
