
cmake_minimum_required(VERSION 3.24)

project(test_cmake)

enable_language(CXX)

list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.3.1/mingw_64")


find_package(Qt6Core)

if (Qt6Core_FOUND)
  message("QT6 FOUND .. ${Qt6Core_INCLUDE_DIRS}")
  include_directories(${Qt6Core_INCLUDE_DIRS})
  #target_link_libraries (${PROJECT_NAME} ${Qt6Core_LIBRARIES})
else(Qt6Core_FOUND)
  message("QT6 NOT FOUND")
endif (Qt6Core_FOUND)


#include_directories("${Qt6Core_INCLUDE_DIR}")
#include_directories("${Qt6Core_INCLUDE_DIR}")

add_executable(${PROJECT_NAME} main.cpp)