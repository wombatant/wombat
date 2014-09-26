cmake_minimum_required(VERSION 2.8.8)

project(wombat)

set(WOMBAT_BUILD_TYPE "Native" CACHE STRING "The type of build to produce(Native/GBA)")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)
include(address_sanitizer)

add_definitions(
	-std=c++11
	-Wall
	-Wsign-compare
	#-Werror
	#--analyze
	#-Os # GCC size optimization flag
)

add_subdirectory(src)
