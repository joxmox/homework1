#!/bin/bash
set -e
set -x

# how to compile a single CPP file without main()
# g++ -std=c++14 -Wall -fmax-errors=1 -c src/lib/foobar.cpp -o build/objs/foobar.o

# how to link a bunch of *.o files into an exe
# g++ build/objs/foobar.o build/objs/app.o -o build/bin/app

g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/lib/StringUtils.cpp -o build/objs/StringUtils.o
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/lib/GenUtils.cpp -o build/objs/GenUtils.o
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/lib/Account.cpp -o build/objs/Account.o
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/app/AccountDBgenerator.cpp -o build/objs/AccountDBgenerator.o

g++ build/objs/StringUtils.o build/objs/Account.o build/objs/GenUtils.o build/objs/AccountDBgenerator.o -o build/bin/AccountDBgenerator

build/bin/AccountDBgenerator -v
