#!/bin/bash

# creating directory build if not exist
mkdir -p build
cd build || exit

# running cmake
cmake ..

# running make
make

# returning to root directory
cd ..
