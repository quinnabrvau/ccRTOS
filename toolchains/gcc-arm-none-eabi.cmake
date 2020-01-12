find_path(ARM_TOOLCHAIN_DIR arm-none-eabi-gcc PATHS ENV Path)

SET(CMAKE_SYSTEM arm-cortex-m3 )
SET(CMAKE_SYSTEM_NAME Generic )
SET(CMAKE_SYSTEM_PROCESSOR cortex-m3 )
set(CMAKE_EXECUTABLE_SUFFIX ".elf")

set(CMAKE_C_COMPILER ${ARM_TOOLCHAIN_DIR}/arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER ${ARM_TOOLCHAIN_DIR}/arm-none-eabi-as)
set(CMAKE_CXX_COMPILER ${ARM_TOOLCHAIN_DIR}/arm-none-eabi-g++)

set(CMAKE_SYSROOT ${ARM_TOOLCHAIN_DIR}/../arm-none-eabi)
set(CMAKE_FIND_ROOT_PATH ${ARM_TOOLCHAIN_DIR}/arm-none-eabi-gcc)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Perform compiler test with static library
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CPP_PLATFORM armcc)

set(CPU_FLAGS "-mthumb -mcpu=cortex-m3 -march=armv7-m -mfloat-abi=soft")
set(COMPILER_FLAGS "-std=gnu++11 -ffreestanding -ffunction-sections -fdata-sections -fsigned-char -fmessage-length=0 -fshort-enums")

