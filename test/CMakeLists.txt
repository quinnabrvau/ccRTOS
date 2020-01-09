project(testPrioQueue)
cmake_minimum_required (VERSION 3.4)
set( SOURCES
    pqNode.cpp
    prioQueue.cpp
    task.cpp
    scheduler.cpp
)
include_directories(
    ../cpputest/include/CppUTest/
)

## Stand alone test executable
add_executable (testPrioQueue_EXE
    ${SOURCES}
    main.cpp
)
target_compile_options(testPrioQueue_EXE
    PRIVATE -DTESTING
)
target_link_libraries(testPrioQueue_EXE
    CppUTest
)

## create make test for this lib
add_test (NAME testPrioQueue COMMAND testPrioQueue_EXE)
