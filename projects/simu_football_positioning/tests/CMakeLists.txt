
cmake_minimum_required(VERSION 3.5)

project(tests)


# # Default to Release build if not specified
# if(NOT CMAKE_BUILD_TYPE)
#     set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type (Release or Debug)" FORCE)
# endif()

# # Add options for debug and release builds
# set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# # For Debug build
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")

# # For Release build
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

find_package(ZEROMQ REQUIRED)
find_package(PROTOBUF REQUIRED)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROTO_FILES ../src/schemas/position.proto)

# Generate C++ code from the protobuf files
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_executable(client client.cpp ${PROTO_SRCS} ${PROTO_HDRS})
add_executable(server server.cpp ${PROTO_SRCS} ${PROTO_HDRS})

set(ZMQ_INC /opt/homebrew/include/)


set(SRC_FILES src/main
              src/generator.hpp
              src/data_publisher_impl.h
              src/data_publisher_impl.cpp
)



target_include_directories(client PRIVATE  ${ZEROMQ_INCLUDE_DIR} ${ZMQ_INC})
target_include_directories(server PRIVATE  ${ZEROMQ_INCLUDE_DIR} ${ZMQ_INC})

target_link_libraries(client PUBLIC  ${ZEROMQ_LIBRARIES} ${Protobuf_LIBRARIES} libzmq)
target_link_libraries(server PUBLIC  ${ZEROMQ_LIBRARIES} ${Protobuf_LIBRARIES}  libzmq)