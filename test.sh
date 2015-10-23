#!/bin/bash
set -e
set -x


###
### Library compile
###
. ./compile.sh

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
g++ ${CXX_FLAGS} -c ${SRCTST}/IOUtilsUnittest.cpp -I${SRCLIB} -o ${OBJS}/IOUtilsUnittest.o
g++ ${CXX_FLAGS} -c ${SRCTST}/StringTest.cpp -I${SRCLIB} -o ${OBJS}/StringTest.o
g++ ${CXX_FLAGS} -c ${SRCTST}/GenTest.cpp -I${SRCLIB} -o ${OBJS}/GenTest.o

###
### Linking
###
g++ ${OBJS}/IOUtils.o ${OBJS}/IOUtilsUnittest.o -o ${BIN}/IOUtilsUnittest
g++ ${OBJS}/GenUtils.o ${OBJS}/GenTest.o -o ${BIN}/GenTest
g++ ${OBJS}/StringUtils.o ${OBJS}/StringTest.o -o ${BIN}/StringTest

${BIN}/IOUtilsUnittest
${BIN}/GenTest
${BIN}/StringTest

