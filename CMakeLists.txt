project(cpp_pro)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

add_subdirectory(singleton)
add_subdirectory(smart_pointer)
add_subdirectory(string)
add_subdirectory(lru)
