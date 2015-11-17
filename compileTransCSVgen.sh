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
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/app/TransCSVgen.cpp -o build/objs/TransCSVgen.o
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/lib/IOUtils.cpp -o build/objs/IOUtils.o
g++ -std=c++14 -Wall -fmax-errors=1 -Isrc/lib -c src/lib/Transaction.cpp -o build/objs/Transaction.o

g++ build/objs/StringUtils.o build/objs/IOUtils.o build/objs/Transaction.o build/objs/Account.o build/objs/GenUtils.o build/objs/TransCSVgen.o -o build/bin/TransCSVgen

build/bin/TransCSVgen -v
