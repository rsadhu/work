project(MyPlayground)
cmake_minimum_required(VERSION 3.16)

set(GENERAL_SOURCES 
		threads.h
		async.h
		parallel_file_read_write.h
		heaps.h
		matrices.h
		g_main.cpp)

set(LEETCODE_SOURCES 
		leetcode_group_anagrams.h
		leetcode_top_k_freq_elems.h
		leetcode_product_array_except.h
		leetcode_encode_decode_str.h
		leetcode_longest_consecutive_arr.h
		lc_main.cpp)



set(CMAKE_CXX_STANDARD 17)



# find_package(DBus REQUIRED)

# include_directories(${DBUS_INCLUDE_DIRS})


add_executable(${CMAKE_PROJECT_NAME}_gen ${GENERAL_SOURCES})
add_executable(${CMAKE_PROJECT_NAME}_lc ${LEETCODE_SOURCES})

# target_link_libraries(${CMAKE_PROJECT_NAME}_server ${DBUS_LIBRARIES})
# target_link_libraries(${CMAKE_PROJECT_NAME}_client ${DBUS_LIBRARIES})


include (FindPkgConfig)
find_package(PkgConfig REQUIRED) # Include functions provided by PkgConfig module.

pkg_check_modules(DBUS REQUIRED dbus-1) # This calls pkgconfig with appropriate arguments
# Use results of pkg_check_modules() call.
include_directories(${DBUS_INCLUDE_DIRS})
link_directories(${DBUS_LIBRARY_DIRS})

#add_executable(${CMAKE_PROJECT_NAME}_server calc_dbus_server.cpp)
add_executable(${CMAKE_PROJECT_NAME}_client calc_dbus_client.cpp)

#target_link_libraries(${CMAKE_PROJECT_NAME}_server dbus-1 dbus-c++-1)
target_link_libraries(${CMAKE_PROJECT_NAME}_client dbus-1 dbus-c++-1 pthread)

