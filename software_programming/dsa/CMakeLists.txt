#
#project(test)
#add_library(dsaLib STATIC Arrays.h BST.h Graphs.h LinkList.h RecursionExamples.h RecursionExamples.cpp Searching.h Sorting.h Stack.h)
#install(TARGETS dsaLib DESTINATION .)
#install(FILES *.h DESTINATION .)
#add_executable(test main.cpp)
#target_link_libraries(dsaLib)

file(GLOB SRCS *.cpp)
file(GLOB HDRS *.h)

add_library(dsa_lib ${SRCS})
add_executable(dsa main.cpp)
target_link_libraries(dsa dsa_lib)

