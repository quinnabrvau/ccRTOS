#!/bin/bash
mkdir -p xcode
pushd xcode

## use cmake to generate make files
cmake -DTESTS=OFF -DC++11=ON -G Xcode ..
if [[ "$?" -ne 0 ]]; then
    exit -1
fi

popd
