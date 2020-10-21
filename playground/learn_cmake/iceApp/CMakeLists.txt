
find_package(Ice REQUIRED COMPONENTS Ice  Glacier2)

if (Ice_FOUND)
    Message(STATUS "Ice found :${Ice_INCLUDE_DIRS}")
else()
    Message("Ice Not Found")
endif()

add_executable(iceApp main.cpp)

target_link_libraries(iceApp ${Ice_LIBRARIES})
