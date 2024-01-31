cmake_minimum_required(VERSION 3.20)

set(CMAKE_BUILD_TYPE Debug)

project(stacktrace)

add_executable(stacktrace stacktrace.cpp)
target_compile_features(stacktrace PRIVATE cxx_std_23)
target_link_libraries(stacktrace PRIVATE stdc++_libbacktrace)
