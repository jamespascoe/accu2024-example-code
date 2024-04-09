cmake_minimum_required(VERSION 3.20)

set (CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)

project(ACCU2024)


link_libraries(stdc++_libbacktrace)

add_executable(stacktrace-fib stacktrace-fib.cpp)
