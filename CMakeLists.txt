cmake_minimum_required(VERSION 3.10)
project(reverse)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(reverse
        main.cpp
        StackType.h
        teebuff.h)
