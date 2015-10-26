app = src/app/
lib = src/lib/
obj = build/objs/
bin = build/bin/

inc = -I$(lib)

cpp = g++
cfl = -std=c++14 -g -c -Wall -fmax-errors=1 -Wno-sign-compare $(inc)
lnk = g++
lfl =

compile = mkdir -p $(obj); $(cpp) $(cfl) $< -o $@
link =    mkdir -p $(bin); $(lnk) $(lfl) $+ -o $@

all : $(bin)bissenisse

clean :
	rm -rf build
 
$(bin)bissenisse : $(obj)bissenisse.o $(obj)GenUtils.o $(obj)IOUtils.o
	$(link)
	
$(obj)bissenisse.o : $(app)bissenisse.cpp $(lib)GenUtils.hpp $(lib)IOUtils.hpp
	$(compile)

$(obj)GenUtils.o : $(lib)GenUtils.cpp $(lib)GenUtils.hpp
	$(compile)
	
$(obj)IOUtils.o : $(lib)IOUtils.cpp $(lib)IOUtils.hpp
	$(compile)
