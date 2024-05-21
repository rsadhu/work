project(logger)


# Default to Release build if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type (Release or Debug)" FORCE)
endif()

# Add options for debug and release builds
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)

# For Debug build
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")

# For Release build
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Find spdlog package
find_package(Boost REQUIRED COMPONENTS system thread)


# Define the library
add_executable(${PROJECT_NAME} main.cpp logger.cpp http_client.h)
target_link_libraries(${PROJECT_NAME} PUBLIC  ${Boost_LIBRARIES})