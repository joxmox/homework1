#!/bin/bash
set -e
set -x

# how to compile a single CPP file without main()
# g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/foobar.cpp -o build/objs/foobar.o

# how to link a bunch of *.o files into an exe
# g++ build/objs/foobar.o build/objs/app.o -o build/bin/app

g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/IOUtils.cpp -o build/objs/IOUtils.o
