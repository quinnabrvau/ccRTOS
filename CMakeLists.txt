set (CMAKE_CXX_STANDARD 11)
cmake_minimum_required (VERSION 3.4)

project(ccRTOS)

add_definitions(${CPU_FLAGS} ${COMPILER_FLAGS})

include_directories(
    include
)
add_subdirectory(cpputest)
enable_testing()
add_subdirectory(test)





message("
-------------------------------------------------------
TOOLCHAIN:

Current compiler options:
    CC:                                 ${CMAKE_C_COMPILER}
    CXX:                                ${CMAKE_CXX_COMPILER}
    ASM:                                ${CMAKE_ASM_COMPILER}
    SYSROOT:                            ${CMAKE_SYSROOT}
    FIND_ROOT_PATH:                     ${CMAKE_FIND_ROOT_PATH}

    SYSTEM:                             ${CMAKE_SYSTEM}
        NAME:                           ${CMAKE_SYSTEM_NAME}
        PROCESSOR:                      ${CMAKE_SYSTEM_PROCESSOR}
        FLAGS:                          ${CPU_FLAGS}
                                        ${COMPILER_FLAGS}

-------------------------------------------------------
")
