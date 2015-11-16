app = src/app/
lib = src/lib/
obj = build/objs/
bin = build/bin/
tst = src/tst/

inc = -I$(lib)

cpp = g++
cfl = -std=c++14 -g -c -Wall -fmax-errors=1 -Wno-sign-compare $(inc)
lnk = g++
lfl =

compile = mkdir -p $(obj); $(cpp) $(cfl) $< -o $@
link =    mkdir -p $(bin); $(lnk) $(lfl) $+ -o $@

all : bissenisse testa

bissenisse : $(bin)bissenisse

testa : $(bin)GenTest $(bin)StringTest $(bin)IOUtilsUnittest

indextest : $(bin)IndexedFile_test

clean :
	rm -rf build

testrun : testa
	$(bin)GenTest && $(bin)StringTest && $(bin)IOUtilsUnittest


 
$(bin)bissenisse : $(obj)bissenisse.o $(obj)GenUtils.o $(obj)IOUtils.o
	$(link)
	
$(obj)bissenisse.o : $(app)bissenisse.cpp $(lib)GenUtils.hpp $(lib)IOUtils.hpp
	$(compile)

$(obj)GenUtils.o : $(lib)GenUtils.cpp $(lib)GenUtils.hpp
	$(compile)
	
$(obj)IOUtils.o : $(lib)IOUtils.cpp $(lib)IOUtils.hpp
	$(compile)
	
$(obj)StringUtils.o : $(lib)StringUtils.cpp $(lib)StringUtils.hpp
	$(compile)

$(bin)GenTest : $(obj)GenTest.o $(obj)GenUtils.o $(lib)GenUtils.hpp
	$(link)
	
$(bin)StringTest : $(obj)StringTest.o $(obj)StringUtils.o $(lib)StringUtils.hpp
	$(link)
	
$(bin)IOUtilsUnittest : $(obj)IOUtilsUnittest.o $(obj)IOUtils.o $(lib)IOUtils.hpp
	$(link)

$(obj)IOUtilsUnittest.o : $(tst)IOUtilsUnittest.cpp $(lib)IOUtils.hpp
	$(compile)
	
$(obj)StringTest.o : $(tst)StringTest.cpp $(lib)StringUtils.hpp
	$(compile)
	
$(obj)GenTest.o : $(tst)GenTest.cpp $(lib)GenUtils.hpp
	$(compile)
	
	
$(obj)IndexedFile_test.o : $(tst)IndexedFile_test.cpp $(lib)IndexedFile.hpp $(lib)text.hpp
	$(compile)

$(bin)IndexedFile_test : $(obj)IndexedFile_test.o
	$(link)
