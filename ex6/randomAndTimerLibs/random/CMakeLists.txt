#create library

cmake_minimum_required(VERSION 3.22)
project(random)

set(CMAKE_CXX_STANDARD 11)

add_library(libRandom STATIC random.cpp)

install(TARGETS libRandom DESTINATION lib)
install(FILES random.hpp DESTINATION include)
