project(cpp_pro)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread" )

add_executable(threadpool_example main.cpp)