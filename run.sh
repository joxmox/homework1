#!/bin/bash
set -e
set -x

CXX_FLAGS="-std=c++14 -Wall -fmax-errors=1"
SRCLIB="src/lib"
SRCAPP="src/app"
SRCTST="src/tst"
OBJS="build/objs"
BIN="build/bin"
INC="-I${SRCLIB}"

g++ ${CXX_FLAGS}  ${INC} -c ${SRCAPP}/bissenisse.cpp -o ${OBJS}/bissenisse.o
g++ ${OBJS}/bissenisse.o ${OBJS}/GenUtils.o ${OBJS}/IOUtils.o -o ${BIN}/bissenisse

${BIN}/bissenisse $*




