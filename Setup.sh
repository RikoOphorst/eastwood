#!/bin/bash

set -e

git submodule init
git submodule update

mkdir -p build
cmake -B build -S .