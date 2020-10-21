cmake_minimum_required(VERSION 3.15)
project(learnCmake)

set(CMAKE_CXX_STANDARD 20)

find_library(ssl_lib libssl.so libssl.dylib libssl.lib HINTS "/usr/lib/x86_64-linux-gnu/openssl-1.0.0/")
find_path(ssl_path HINTS "/usr/lib/x86_64-linux-gnu/openssl-1.0.0/")

# if (ssl_lib_FOUND)
#     Message("ssl lib found ")
# elseif()
#     Message("ssl lib not found")
# endif()

# if (ssl_path_FOUND)
#     Message("ssl path found")
# elseif()
#     Message("ssl path not found")
# endif()

Message(STATUS " ssl_libraries "${ssl_lib})
Message(STATUS " ssl paths "${ssl_path})
add_library(fooLib SHARED someheader.h someimpl.cpp)

add_executable(learnCmake main.cpp someimpl.cpp)
target_link_libraries(learnCmake fooLib ${ssl_lib})
