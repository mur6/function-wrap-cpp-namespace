#!/bin/bash

build() {
    BUILD_DIR=build
    echo "BUILD_DIR: $BUILD_DIR"
    cmake -B $BUILD_DIR -S .
    cmake --build $BUILD_DIR
}

# test() {
#     BUILD_DIR=build
#     echo "BUILD_DIR: $BUILD_DIR"
#     cd $BUILD_DIR || exit
#     ./main
# }


# switch by the first argument
case $1 in
    "clean")
        clean
        ;;
    "build")
        build
        ;;
    "test")
        test
        ;;
    *)
        echo "Usage: $0 {clean|build|test}"
        exit 1
        ;;
esac
