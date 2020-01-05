
## make sure build directory is available
mkdir -p build

pushd build

## use cmake to generate make files
cmake ..
if [[ "$?" -ne 0 ]]; then
    exit -1
fi

## use make files to build project
make -j3
if [[ "$?" -ne 0 ]]; then
    exit -2
fi

## test project
./test/testPrioQueue_EXE
if [[ "$?" -ne 0 ]]; then
    exit -3
fi

popd
