#!/bin/bash

# set environment variables to identify
# compilers, assemblers, and path to PICO SDK
# as running as sudo (Root) won't know these
export C="arm-none-eabi-gcc"
export CXX="arm-none-eabi-g++"
export ASM="arm-none-eabi-gcc"
export PICO_SDK_PATH="/home/tardis1/pico/pico-sdk"

# Run cmake on the parent directory,
# the one with the source and CMakeLists.txt
# in order to build everything needed to create
# PICO *.uf2 file
cmake ..

