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

g++ ${CXX_FLAGS} -c ${SRCTST}/IndexedFile_test.cpp -I${SRCLIB} -o ${OBJS}/IndexedFile_test.o
g++ ${CXX_FLAGS} -c ${SRCTST}/integer_test.cpp -I${SRCLIB} -o ${OBJS}/integer_test.o
g++ ${CXX_FLAGS} -c ${SRCTST}/text_test.cpp -I${SRCLIB} -o ${OBJS}/text_test.o


###
### Linking
###
g++ ${OBJS}/IOUtils.o ${OBJS}/IOUtilsUnittest.o -o ${BIN}/IOUtilsUnittest
g++ ${OBJS}/GenUtils.o ${OBJS}/GenTest.o -o ${BIN}/GenTest
g++ ${OBJS}/StringUtils.o ${OBJS}/StringTest.o -o ${BIN}/StringTest

g++ ${OBJS}/IndexedFile.o ${OBJS}/IndexedFile_test.o -o ${BIN}/IndexedFile_test
g++ ${OBJS}/integer.o ${OBJS}/integer_test.o -o ${BIN}/integer_test
g++ ${OBJS}/text.o ${OBJS}/text_test.o -o ${BIN}/text_test


${BIN}/IOUtilsUnittest
${BIN}/GenTest
${BIN}/StringTest

${BIN}/IndexedFile_test
${BIN}/integer_test
${BIN}/text_test


