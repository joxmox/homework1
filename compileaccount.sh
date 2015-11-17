#!/bin/bash
set -e
set -x

# how to compile a single CPP file without main()
# g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/foobar.cpp -o build/objs/foobar.o

# how to link a bunch of *.o files into an exe
# g++ build/objs/foobar.o build/objs/app.o -o build/bin/app

g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/lib/StringUtils.cpp -o build/objs/StrungUtils.o
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/lib/Account.cpp -o build/objs/Account.o
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/tst/Account_test.cpp -o build/objs/Account_test.o

g++ build/objs/StringUtils.o build/objs/Account.o build/objs/Account_test.o -o build/bin/Account_test

build/bin/Account_test
