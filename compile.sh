#!/bin/bash
set -e
set -x

# how to compile a single CPP file without main()
# g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/foobar.cpp -o build/objs/foobar.o

# how to link a bunch of *.o files into an exe
# g++ build/objs/foobar.o build/objs/app.o -o build/bin/app


# how to tell the compiler where to find include files
# included by '#include "foobar.hpp"'
# g++ -Isrc/lib ...


# how to create a variable
# CXX_FLAGS="-std=c++14 -Wall -fmax-errors=1"

# how to use a variable
# g++ ${CXX_FLAGS} -c ${SRCLIB}/foobar.cpp -o ${OBJS}/foobar.o


g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/IOUtils.cpp -o build/objs/IOUtils.o
