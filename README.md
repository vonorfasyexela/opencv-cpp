# Digging OpenCV

Tested development platforms:
* msys2 (the most recent OpenCV)
* Ubuntu 16.04 (OpenCV 2.4.9.1)
* Ubuntu 18.04 (OpenCV 3.2.0)

Ubuntu setup:

    sudo apt install cmake build-essential pkg-config libopencv-dev

## 01. Hello World

What illustrates:
* different methods to plug the library
* getting compile-time version
* getting run-time version (where possible)
* printing build information

To build use these commands:

    mkdir build && cd build
    cmake -G "Unix Makefiles" -DFULL_OPENCV=OFF ..
    make VERBOSE=1
