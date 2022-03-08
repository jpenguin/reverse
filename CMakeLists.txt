cmake_minimum_required(VERSION 3.10)
project(reverse)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(reverse
        main.cpp
        reverse.cpp
        reverse_more.cpp
        StackType.cpp)

# Add debugging option
option(CPP_STANDARD_STACK "Uses std::stack implementation" OFF)
if (CPP_STANDARD_STACK)
    add_definitions(-SSTACK)
endif()