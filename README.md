# wrap function

## キーワード

- c++
- emscripten
- opencv
- clang
- リンカー, GNU ld
- wrapオプション

## Prerequisite

You need to have emscripten, and OpenCV installed.

See here to install emscripten:
- https://emscripten.org/docs/getting_started/downloads.html

To build OpenCV with Emscripten, see here:
- https://docs.opencv.org/master/d4/da1/tutorial_js_setup.html


## Build

```bash
export WASM_COMPILED_OPENCV_DIR=/path/to/opencv_projects/build_wasm-latest
emcmake cmake -DOpenCV_DIR=$WASM_COMPILED_OPENCV_DIR -B build -S .
cmake --build build
```

So, it will generate `build/main.js`.

## Run

```bash
node ./build/main.js
```
