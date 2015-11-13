#!/bin/bash
set -e
set -x

###
### Create directories
###
mkdir -p build/{objs,bin}

###
### Variables
###
CXX_FLAGS="-std=c++14 -Wall -fmax-errors=1 -Wno-sign-compare"
SRCLIB="src/lib"
SRCTST="src/tst"
OBJS="build/objs"
BIN="build/bin"

###
### Compile
###
g++ ${CXX_FLAGS} -c ${SRCLIB}/IOUtils.cpp -o ${OBJS}/IOUtils.o
g++ ${CXX_FLAGS} -c ${SRCLIB}/StringUtils.cpp -o ${OBJS}/StringUtils.o
g++ ${CXX_FLAGS} -c ${SRCLIB}/GenUtils.cpp -o ${OBJS}/GenUtils.o

g++ ${CXX_FLAGS} -c ${SRCLIB}/boolean.hpp -o ${OBJS}/boolean.o
g++ ${CXX_FLAGS} -c ${SRCLIB}/integer.hpp -o ${OBJS}/integer.o
g++ ${CXX_FLAGS} -c ${SRCLIB}/real.hpp -o ${OBJS}/real.o
g++ ${CXX_FLAGS} -c ${SRCLIB}/text.hpp -o ${OBJS}/text.o
g++ ${CXX_FLAGS} -c ${SRCLIB}/IndexedFile.hpp -o ${OBJS}/IndexedFile.o

###
### Linking
###

