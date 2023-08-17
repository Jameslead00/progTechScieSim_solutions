#make the library
cmake_minimum_required(VERSION 3.22)
project(timer)
set(CMAKE_CXX_STANDARD 11)

add_library(libTimer STATIC timer.cpp)

install(TARGETS libTimer DESTINATION lib)
install(FILES timer.hpp DESTINATION include)