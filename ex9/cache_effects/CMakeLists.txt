# Programming Techniques for Scientific Simulations I
# HS 2022
# Exercise 9.1

cmake_minimum_required (VERSION 3.15)
project (cache_effects)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)
set (CMAKE_CXX_EXTENSIONS FALSE)

add_compile_options (-Wall -Wextra -Wpedantic -march=native -fno-tree-vectorize)
set (CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

add_executable (cache cache.cpp)

add_custom_command (OUTPUT data.csv COMMAND cache > data.csv DEPENDS cache)
add_custom_target (data DEPENDS data.csv)

add_custom_command (OUTPUT plot.png COMMAND ${CMAKE_SOURCE_DIR}/plot.py data.csv plot.png DEPENDS ${CMAKE_SOURCE_DIR}/plot.py data.csv)
add_custom_target (plot DEPENDS plot.png)

#add_executable (cpuid cpuid.cpp)
#add_executable (demo demo.cpp)
