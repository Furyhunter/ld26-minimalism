project(minimalism)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules")

if (UNIX)
    set(CMAKE_CXX_FLAGS "--std=c++11")
endif (UNIX)

add_subdirectory(src)
