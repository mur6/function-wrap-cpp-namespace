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
cd build
emcmake cmake -DOpenCV_DIR={WASM_COMPILED_OPENCV_DIR}/build_wasm ..
emmake make
cd ..
```

So, it will generate `build/main.js`.

## build

```sh
sh make.sh build
```

## execute

```sh
sh make.sh exec_main
```
