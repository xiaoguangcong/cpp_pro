project(singleton)

CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

add_executable(singleton_example main.cpp)