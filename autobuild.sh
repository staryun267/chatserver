#!/bin/bash

set -x

mkdir -p build
mkdir -p bin

rm -rf build/*
rm -rf bin/*

cd  build &&
    cmake .. &&
    make