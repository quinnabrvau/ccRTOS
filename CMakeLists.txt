set (CMAKE_CXX_STANDARD 11)
set (C++11 ON CACHE BOOL "use C++11" FORCE)
cmake_minimum_required (VERSION 3.4)

project(prioQueue)
include_directories(
    include
)
add_subdirectory(cpputest)
enable_testing()
add_subdirectory(test)

