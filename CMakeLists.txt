set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required (VERSION 3.4)

project(ccRTOS)
include_directories(
    include
)
add_subdirectory(cpputest)
enable_testing()
add_subdirectory(test)

