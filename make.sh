#!/bin/bash

build_em() {
    BUILD_DIR=build
    echo "BUILD_DIR: $BUILD_DIR"
    rm -rf $BUILD_DIR
    emcmake cmake -DOpenCV_DIR=$WASM_COMPILED_OPENCV_DIR -B build -S .
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
    "build_em")
        build_em
        ;;
    "exec_main")
        exec_main
        ;;
    *)
        echo "Usage: $0 {clean|build_em|exec_main}"
        exit 1
        ;;
esac
