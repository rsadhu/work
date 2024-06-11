cmake_minimum_required(VERSION 3.10)
project(PositionGenerator)

# Default to Release build if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type (Release or Debug)" FORCE)
endif()

# Add options for debug and release builds
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# For Debug build
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")

# For Release build
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(ZEROMQ REQUIRED)
find_package(PROTOBUF REQUIRED)

set(PROTO_FILES src/schemas/position.proto)
set(SRC_FILES src/main
              src/generator.hpp
              src/data_publisher_impl.h
              src/data_publisher_impl.cpp
)

# Generate C++ code from the protobuf files
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})


# Define the library
add_executable(${PROJECT_NAME}  ${PROTO_SRCS} ${PROTO_HDRS} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Protobuf_INCLUDE_DIRS} ${ZMQ_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC  ${ZEROMQ_LIBRARIES} ${Protobuf_LIBRARIES} libzmq)