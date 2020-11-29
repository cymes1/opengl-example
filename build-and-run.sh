#!/bin/bash

# creating directory build if not exist
mkdir -p build
cd build || exit

# running cmake
if ! cmake ..; then
  exit 1
fi

# running make
if ! make; then
  exit 1
fi

# copy program resources
if [ -d build/bin/res ]; then
  rm -r build/bin/res/
fi
cp -r ../res build/bin/

# running tests
cd build/bin || exit
if ! ./opengl-test-test; then
  exit 1
fi

# running program
./opengl-test

# returning to root directory
cd ..
