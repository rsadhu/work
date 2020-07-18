cmake_minimum_required(VERSION 3.16)
project(software_programming)

set(CMAKE_CXX_STANDARD 14)

include_directories(adv_dsa)
include_directories(dsa)

add_executable(software_programming
        adv_dsa/Map.cpp
        adv_dsa/Map.h
        adv_dsa/test.cpp
        dsa/Arrays.h
        dsa/BST.h
        dsa/Graphs.h
        dsa/LinkList.h
        dsa/main.cpp
        dsa/RecursionExamples.h
        dsa/Searching.h
        dsa/Sorting.h
        dsa/Stack.h
        practice/coding.cpp
        practice/CrackingCodingInterviewQuestions.cpp
        practice/MockInterviewOzi.cpp
        practice/prog.cpp
        #practice/wk2.cpp
        main.cpp
        test.cpp practice/wk2.cpp)


#add_executable(leetCode practice/coding.cpp)


add_executable(leetcode practice/wk2.cpp)