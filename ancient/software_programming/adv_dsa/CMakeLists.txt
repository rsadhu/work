FILE(GLOB SRCS *.cpp)
FILE(GLOB HDRS *.h)

add_library(adv_dsa ${SRCS} test.cpp)

add_executable(test_adv_dsa test.cpp)

target_link_libraries(test_adv_dsa adv_dsa)