cmake_minimum_required(VERSION 3.10)
project(CircleAnimation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(ZEROMQ REQUIRED)
find_package(PROTOBUF REQUIRED)
find_package(absl REQUIRED)


set(PROTO_FILES ../src/schemas/position.proto)

# Generate C++ code from the protobuf files
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_executable(CircleAnimation main.cpp zeromq_client.cpp graphicsview.cpp graphicsview.h ${PROTO_SRCS} ${PROTO_HDRS})


target_include_directories(${PROJECT_NAME} PRIVATE  ${ZEROMQ_INCLUDE_DIR} ${ZMQ_INC})
target_link_libraries(CircleAnimation Qt6::Widgets ${Protobuf_LIBRARIES} libzmq  absl::log_internal_message
absl::log_internal_check_op)
