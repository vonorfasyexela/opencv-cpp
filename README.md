# Digging OpenCV

Tested development platforms:
* Windows/msys2
* Ubuntu 18.04

On both platforms OpenCV is built from sources and installed into **/opt/opencv**.

## 01. Hello World

What illustrates:
* how to select which OpenCV build to use
* getting compile-time version
* getting run-time version (where possible)
* printing build information

To build use these commands:

    $ mkdir build && cd build
    $ OPENCV_INSTALL_DIR="/opt/opencv" cmake -G "Unix Makefiles" ..
    $ make
