cmake_minimum_required(VERSION 3.27)
project(BigInt)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BigInt
        main.cpp
        main.h)
