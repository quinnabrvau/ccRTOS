#!/bin/bash

mkdir -p clang-cc-build

pushd clang-cc-build

## use cmake to generate make files
cmake   -DTESTS=OFF \
        -DC++11=ON \
        -DCMAKE_TOOLCHAIN_FILE=../toolchains/ubuntu/clang-arm-none-eabi.cmake \
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
