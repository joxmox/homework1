##### Locations

app = src/app/
lib = src/lib/
obj = build/objs/
bin = build/bin/
tst = src/tst/
inc = -I$(lib)

##### Build settings

cpp = g++
cfl = -std=c++14 -g -c -Wall -fmax-errors=1 -Wno-sign-compare $(inc)
lnk = g++
lfl =
compile = mkdir -p $(obj); $(cpp) $(cfl) $< -o $@
link =    mkdir -p $(bin); $(lnk) $(lfl) $+ -o $@
run = $<

##### Targets to use

all : AccountDBgenerator
	
clean :
	rm -rf build

bissenisse : $(bin)bissenisse
	$(run)

index_test : $(bin)IndexedFile_test
	$(run)

text_test : $(bin)text_test
	$(run)
	
integer_test : $(bin)integer_test
	$(run)
	
real_test : $(bin)real_test
	$(run)
	
boolean_test : $(bin)boolean_test
	$(run)
	
AccountDBgenerator : $(bin)AccountDBgenerator
	$(run)

AccountsDbDumper : $(bin)AccountsDbDumper
	$(run)
	
ProcessTrans : $(bin)ProcessTrans
	$(run)

GenTest : $(bin)GenTest
	$(run)
	
StringTest : $(bin)StringTest
	$(run)

IOUtilsUnittest : $(bin)IOUtilsUnittest
	$(run)
	
Account_test : $(bin)Account_test
	$(run)
	
all_tests : index_test text_test integer_test real_test boolean_test


##### Build the application bissenisse
 
$(bin)bissenisse : $(obj)bissenisse.o $(obj)GenUtils.o $(obj)IOUtils.o
	$(link)
	
$(obj)bissenisse.o : $(app)bissenisse.cpp $(lib)GenUtils.hpp $(lib)IOUtils.hpp
	$(compile)
	

##### Build objects for Gen, IO and String utils

$(obj)GenUtils.o : $(lib)GenUtils.cpp $(lib)GenUtils.hpp
	$(compile)
	
$(obj)IOUtils.o : $(lib)IOUtils.cpp $(lib)IOUtils.hpp
	$(compile)
	
$(obj)StringUtils.o : $(lib)StringUtils.cpp $(lib)StringUtils.hpp
	$(compile)


##### Build test programs for Gen IO and String Util functions 

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



##### Build the test file for the IndexedFile class

$(obj)IndexedFile_test.o : $(tst)IndexedFile_test.cpp $(lib)IndexedFile.hpp $(lib)text.hpp
	$(compile)
	

	
##### Build the test files for the text, integer, real and boolean data types

$(bin)IndexedFile_test : $(obj)IndexedFile_test.o
	$(link)
	
$(obj)text_test.o : $(tst)text_test.cpp $(lib)text.hpp
	$(compile)
	
$(bin)text_test : $(obj)text_test.o
	$(link)
	
$(obj)integer_test.o : $(tst)integer_test.cpp $(lib)integer.hpp
	$(compile)
	
$(bin)integer_test : $(obj)integer_test.o
	$(link)
	
$(obj)real_test.o : $(tst)real_test.cpp $(lib)real.hpp
	$(compile)
	
$(bin)real_test : $(obj)real_test.o
	$(link)
	
$(obj)boolean_test.o : $(tst)boolean_test.cpp $(lib)boolean.hpp
	$(compile)
	
$(bin)boolean_test : $(obj)boolean_test.o
	$(link)
	


##### Build the Account and Transaction classes
	
$(obj)Account.o : $(lib)Account.cpp $(lib)Account.hpp 
	$(compile)
	
$(obj)Transaction.o : $(lib)Transaction.cpp $(lib)Transaction.hpp
	$(compile)
	

##### Build the test files for the text, integer, real and boolean data types

$(bin)Account_test : $(obj)Account.o $(obj)StringUtils.o $(obj)Account_test.o
	$(link)
	
$(obj)Account_test.o : $(tst)Account_test.cpp $(lib)text.hpp
	$(compile)

##### build the Homework2 applications

##### AccountDBgenerator
$(bin)AccountDBgenerator : $(obj)AccountDBgenerator.o $(obj)Account.o $(obj)StringUtils.o $(obj)GenUtils.o
	$(link)

$(obj)AccountDBgenerator.o : $(app)AccountDBgenerator.cpp $(lib)IndexedFile.hpp $(lib)StringUtils.hpp $(lib)GenUtils.hpp $(lib)IOUtils.hpp
	$(compile)
	
##### build the db dumper  application
$(bin)AccountsDbDumper : $(obj)AccountsDbDumper.o $(obj)Account.o 
	$(link)

$(obj)AccountsDbDumper.o : $(app)AccountsDbDumper.cpp $(lib)IndexedFile.hpp 
	$(compile)

##### build the Process Transactions application

$(bin)ProcessTrans : $(obj)ProcessTrans.o $(obj)Account.o $(obj)Transaction.o $(obj)StringUtils.o
	 $(link)
	 
$(obj)ProcessTrans.o : $(app)ProcessTrans.cpp $(lib)Account.hpp $(lib)IndexedFile.hpp $(lib)Transaction.hpp
	$(compile)