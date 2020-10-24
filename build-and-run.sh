#!/bin/bash

# creating directory build if not exist
mkdir -p build
cd build || exit

# running cmake
cmake ..

# running make
make

# running program
cd build/bin || exit
./opengl-test

# returning to root directory
cd ../../../
