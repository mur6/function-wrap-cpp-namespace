#!/bin/bash

# CXX_COMPILER=/usr/local/Cellar/llvm/19.1.1/bin/clang++
CXX_COMPILER=/usr/local/Cellar/gcc/14.2.0/bin/g++-14
OPENCV_VERSION=4.10.0_10
OPENCV_INCLUDE_DIR="/usr/local/Cellar/opencv/${OPENCV_VERSION}/include/opencv4"
OPENCV_LIB_DIR="/usr/local/Cellar/opencv/${OPENCV_VERSION}/lib"

# compile with opencv2 library
$CXX_COMPILER -std=c++17 -I${OPENCV_INCLUDE_DIR} \
    -L${OPENCV_LIB_DIR} -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs \
    -fuse-ld=lld -Wl,--wrap=cv_imread -o main main.cpp
