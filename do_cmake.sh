#!/bin/bash

cd $(dirname $(realpath $0))
test -d build/ && rm -rf build/
mkdir build && cd build
cmake ..
