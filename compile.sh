#!/bin/bash
set -e
set -x

#create directories
mkdir -p build/{objs,bin}

# how to compile a single CPP file without main()
# g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/foobar.cpp -o build/objs/foobar.o

# how to link a bunch of *.o files into an exe
# g++ build/objs/foobar.o build/objs/app.o -o build/bin/app


# how to tell the compiler where to find include files
# included by '#include "foobar.hpp"'
# g++ -Isrc/lib ...


# how to create a variable
CXX_FLAGS="-std=c++14 -Wall -fmax-errors=1"
SRCLIB="src/lib"
SRCTST="src/tst"
OBJS="build/objs"
BIN="build/bin"

# how to use a variable
# g++ ${CXX_FLAGS} -c ${SRCLIB}/foobar.cpp -o ${OBJS}/foobar.o


g++ ${CXX_FLAGS} -c ${SRCLIB}/IOUtils.cpp -o ${OBJS}/IOUtils.o

g++ ${CXX_FLAGS} -c ${SRCLIB}/GenUtils.cpp -o ${OBJS}/GenUtils.o
g++ ${CXX_FLAGS} -c ${SRCTST}/GenTest.cpp -I${SRCLIB} -o ${OBJS}/GenTest.o

g++ ${OBJS}/GenUtils.o ${OBJS}/GenTest.o -o ${BIN}/GenTest
