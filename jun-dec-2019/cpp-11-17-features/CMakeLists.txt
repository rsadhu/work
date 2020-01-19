add_executable(auto autotype.cpp)
add_executable(init initializerlist.cpp)
add_executable(r-l-out r-l-value-refs.cpp)
add_executable(programming_questions tests.cpp)

include_directories(programming_questions /home/rsadhu/dev/myDev/Catch2/include)

target_link_libraries(programming_questions PUBLIC Catch2)
