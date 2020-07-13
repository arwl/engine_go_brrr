#!/usr/bin/env bash

packages="glfw3 glew"
bin_name="main"

cc $(pkg-config --cflags $packages) -o $bin_name main.c $(pkg-config --libs $packages)
