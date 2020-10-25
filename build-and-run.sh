#!/bin/bash

# creating directory build if not exist
mkdir -p build
cd build || exit

# running cmake
cmake ..

# running make
make

# copy program resources
if [ -d build/bin/res ]; then
  rm -r build/bin/res/
fi
cp -r ../res build/bin/

# running program
cd build/bin || exit
./opengl-test

# returning to root directory
cd ../../../
