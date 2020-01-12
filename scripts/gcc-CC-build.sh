#!/bin/bash



## create clean build directory
rm -r gcc-cc-build
mkdir -p gcc-cc-build

pushd gcc-cc-build

## todo enable memory leak detection

## use cmake to generate make files
cmake   -DTESTS=OFF \
        -DC++11=ON \
        -DSTD_C=ON \
        -DSTD_CPP=ON \
        -DMEMORY_LEAK_DETECTION=OFF \
        -DCMAKE_TOOLCHAIN_FILE=../toolchains/gcc-arm-none-eabi.cmake \
        -DEXTENSIONS=OFF \
        ..
if [[ "$?" -ne 0 ]]; then
    exit -1
fi

## use make files to build project
make
if [[ "$?" -ne 0 ]]; then
    exit -2
fi

popd
