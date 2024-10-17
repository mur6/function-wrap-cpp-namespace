# wrap function

## キーワード

- c++
- emscripten
- opencv
- 名前空間
- ~~リンカー, GNU ld~~
- ~~wrapオプション~~

## Prerequisite

You need to have emscripten, and OpenCV installed.

See here to install emscripten:
- https://emscripten.org/docs/getting_started/downloads.html

To build OpenCV with Emscripten, see here:
- https://docs.opencv.org/master/d4/da1/tutorial_js_setup.html


## Build

```bash
export WASM_COMPILED_OPENCV_DIR=/path/to/opencv_projects/build_wasm-latest
bash make.sh build_em
```

So, it will generate `build/main.js`.

## Run

```bash
node ./build/main.js
```
