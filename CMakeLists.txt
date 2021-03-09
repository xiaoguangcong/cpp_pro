project(cpp_pro)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)    

add_subdirectory(singleton)
add_subdirectory(smart_pointer)
add_subdirectory(string)
add_subdirectory(lru)
add_subdirectory(sort)
