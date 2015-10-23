#!/bin/bash
set -e
set -x

g++ -std=c++14 -Wall -Isrc/lib -fmax-errors=1 -c src/lib/StringUtils.cpp -o build/objs/StringUtils.o





