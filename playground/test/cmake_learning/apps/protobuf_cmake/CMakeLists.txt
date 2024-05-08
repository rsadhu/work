cmake_minimum_required(VERSION 3.29)
project(test_protobufs)

find_package(Protobuf REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

message("protobuf includes are ${Protobuf_INCLUDE_DIRS}")
message("protobuf libs  are ${Protobuf_LIBRARIES}")


include_directories(${PROJECT_NAME} ${Protobuf_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES})