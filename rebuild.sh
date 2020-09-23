#!/bin/bash

echo '************************************'
echo '****** Setting up application ******'
echo '************************************'

rm -rf build
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ..
make -j 16

echo '************************************'
echo '******          Done          ******'
echo '************************************'
