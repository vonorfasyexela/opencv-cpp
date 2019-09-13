# Digging OpenCV
Tested development platforms:
* msys2
* Ubuntu 16.04
* Ubuntu 18.04

## 01. Hello World
To build use these commands:

    mkdir build && cd build
    cmake -g "Unix Makefiles" -DFULL_OPENCV=OFF ..
    make VERBOSE=1