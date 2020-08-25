#!/bin/bash
reset
buildDir="build"

echo '************************************'
echo '******        Building        ******'
echo '************************************'

if [ ! -d "$buildDir" ]; then
    echo '************************************'
    echo '****** Build dir not yet present, starting initial configuration ******'
    echo '************************************'
    sh ./rebuild.sh
else
    echo '************************************'
    echo '******   Already configured   ******'
    echo '************************************'
fi

cd build
make -j 16 install

echo '************************************'
echo '******          Done          ******'
echo '************************************'
