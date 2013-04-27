cmake_minimum_required(VERSION 2.6)

project(minimalism)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

if (UNIX)
    set(CMAKE_CXX_FLAGS "--std=c++11 -ggdb")
endif (UNIX)

add_subdirectory(src)
