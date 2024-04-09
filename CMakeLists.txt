cmake_minimum_required(VERSION 3.20)

set (CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)

project(ACCU2024)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

find_package(Boost COMPONENTS coroutine)

link_libraries(stdc++_libbacktrace)

add_executable(stacktrace-fib stacktrace-fib.cpp)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    add_executable(coro_http_server coro_http_server.cpp)
    target_link_libraries(coro_http_server Threads::Threads)
    target_link_libraries(coro_http_server ${Boost_LIBRARIES})
endif()
