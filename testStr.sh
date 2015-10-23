#!/bin/bash
set -e
set -x

g++ -std=c++14 -Wall -Isrc/lib -fmax-errors=1 -c src/lib/StringUtils.cpp -o build/objs/StringUtils.o
g++ -std=c++14 -Wall -Isrc/lib -fmax-errors=1 -c src/tst/StringTest.cpp -o build/objs/StringTest.o

 g++ build/objs/StringTest.o build/objs/StringUtils.o -o build/bin/StringTest

build/bin/StringTest