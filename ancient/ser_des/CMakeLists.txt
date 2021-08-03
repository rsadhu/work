project(AfdrSerializer)

cmake_minimum_required(VERSION 3.19)

set(CMAKE_BUILD_TYPE Debug)

set(SRCS  main.cpp)
set(CMAKE_CXX_STANDARD 17)


include_directories(/Users/rsadhu/dev/cereal/include/)
include_directories(pods)


add_executable(${CMAKE_PROJECT_NAME} ${SRCS})

target_link_libraries(${CMAKE_PROJECT_NAME})


