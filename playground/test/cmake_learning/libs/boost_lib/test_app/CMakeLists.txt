cmake_minimum_required(VERSION 3.20)
project(test_app_lib)


add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC "/Users/rakeshsadhu/dev/mygit/work/playground/test/cmake_learning/libs/boost_lib/build")
target_link_libraries(${PROJECT_NAME}
"/Users/rakeshsadhu/dev/mygit/work/playground/test/cmake_learning/libs/boost_lib/build/libcustom_boost_lib.dylib")