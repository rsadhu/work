
cmake_minimum_required(VERSION 3.5)

project(tests)

find_package(ZEROMQ REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(client client.cpp)
add_executable(server server.cpp)
set(ZMQ_INC /opt/homebrew/include/)

target_include_directories(client PRIVATE  ${ZEROMQ_INCLUDE_DIR} ${ZMQ_INC})
target_include_directories(server PRIVATE  ${ZEROMQ_INCLUDE_DIR} ${ZMQ_INC})

target_link_libraries(client PUBLIC  ${ZEROMQ_LIBRARIES}  libzmq)
target_link_libraries(server PUBLIC  ${ZEROMQ_LIBRARIES}  libzmq)