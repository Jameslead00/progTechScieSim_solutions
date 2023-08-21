cmake_minimum_required(VERSION 3.11)
project (containers LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED TRUE)
set (CMAKE_CXX_EXTENSIONS FALSE)

if (
	   "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"
	OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
)
	set (CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
endif ()

add_subdirectory (timer)

add_executable (containers containers.cpp)
target_link_libraries (containers timer)

add_custom_command (
	OUTPUT  containers.dat
	COMMAND containers > containers.dat
	DEPENDS containers
)

add_custom_command (
	OUTPUT  containers.png
	COMMAND ${CMAKE_SOURCE_DIR}/plot.py containers.dat containers.png
	DEPENDS ${CMAKE_SOURCE_DIR}/plot.py containers.dat
)

add_custom_target (
	plots ALL
	DEPENDS containers.png
)
