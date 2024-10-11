#!/bin/bash

build() {
    BUILD_DIR=build
    echo "BUILD_DIR: $BUILD_DIR"
    cmake -B $BUILD_DIR -S .
    cmake --build $BUILD_DIR
}

exec_main() {
    BUILD_DIR=build
    COMMAND=$BUILD_DIR/main
    echo "execute: $COMMAND"
    $COMMAND
}

# switch by the first argument
case $1 in
    "clean")
        clean
        ;;
    "build")
        build
        ;;
    "exec_main")
        exec_main
        ;;
    *)
        echo "Usage: $0 {clean|build|exec_main}"
        exit 1
        ;;
esac
