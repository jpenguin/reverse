cmake_minimum_required(VERSION 3.10)
project(reverse)

set(CMAKE_CXX_STANDARD 14)

# This allows us to add flags to all compiler calls
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra")

include_directories(.)

add_executable(reverse
        main.cpp
        reverse.cpp
        reverse_more.cpp
        StackType.cpp)

# Add debugging option
option(STACK "Uses std::stack implementation" OFF)
if (STACK)
    add_definitions(-DCPP_STANDARD_STACK)
endif()