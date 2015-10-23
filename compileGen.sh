#!/bin/bash
set -e
set -x

# how to compile a single CPP file without main()
# g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/foobar.cpp -o build/objs/foobar.o

# how to link a bunch of *.o files into an exe
#g++ build/objs/foobar.o build/objs/app.o -o build/bin/app

mkdir -p build/{objs,bin}

g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/GenUtils.cpp -o build/objs/GenUtils.o
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/tst/GenTest.cpp -o build/objs/GenTest.o

g++ build/objs/GenUtils.o build/objs/GenTest.o -o build/bin/GenTest
