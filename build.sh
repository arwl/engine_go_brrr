#!/usr/bin/env bash

packages="glfw3 glew"
bin_name="main"
compile_flags=$(pkg-config --cflags $packages)
lib_flags=$(pkg-config --libs $packages)

cc $compile_flags -o $bin_name main.c $lib_flags
