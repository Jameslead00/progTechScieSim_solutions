cmake_minimum_required(VERSION 3.1)
project(timer)

set(CMAKE_CXX_STANDARD 11)

add_library(timer STATIC timer.cpp)

install(TARGETS timer DESTINATION lib)
install(FILES timer.hpp DESTINATION include)
