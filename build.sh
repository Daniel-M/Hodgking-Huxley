#!/bin/bash
echo "[ii] Starting Build"
rm -rf build
mkdir build
cd build
cmake ..
make
echo "[ii] Process ended"
