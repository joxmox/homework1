/*
 * IOUtilsUnittest.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: karl
 */

#include "IOUtils.hpp"
#include <cassert>
#include <cstdio>
#include <iostream>

void testTextFunctions() {
	string filename(tmpnam(NULL));
	string test = "abcdefghijklmnopqrstuvwxyz";

	seb::io::text(filename, test);
	string read = seb::io::text(filename);

	assert(read == test);
	remove(filename.c_str());
}

void testLinesFunctions() {
	string filename(tmpnam(NULL));
	vector<string> input = {"test1", "test2", "test3"};

	seb::io::lines(filename, input);
	vector<string> output;
	output = seb::io::lines(filename);
	assert( input.size() == output.size() );
	assert( equal( input.begin(), input.end(), output.begin() ) );
	remove(filename.c_str());
}

void testSizeFunctions() {
	string filename(tmpnam(NULL));
	seb::io::text(filename, "storlekstest");
	assert(seb::io::size(filename) == 12);
	remove(filename.c_str());
}


void testLoadStoreFunctions() {
	struct SimpleRecord {
		int value;
	};
	string filename(tmpnam(NULL));
	for(int index=0;index<10; index++) {
		SimpleRecord sr = {index};
		seb::io::store(filename, index, sizeof(sr), (char*)&sr);
	}
	SimpleRecord out_record;
	seb::io::load(filename, 4, sizeof(out_record), (char*)&out_record);
	assert( out_record.value == 4);
	remove(filename.c_str());

}

void testLoadStoreFunctions2() {
	struct AdvancedRecord {
		unsigned iValue;
		double dValue;
		float fValue;
	};
	string filename(tmpnam(NULL));
	for(int index=0;index<10; index++) {
		AdvancedRecord ar = {index, 1.11111d + index, 1.22222f + index};
		cout << "int: " << ar.iValue << " double: "<< ar.dValue << " float: " << ar.fValue << endl;
		seb::io::store(filename, index, sizeof(AdvancedRecord), reinterpret_cast<char*>(&ar));
	}


	AdvancedRecord out_record;
	for(int index=0;index<10; index++) {
		seb::io::load(filename, index, sizeof(AdvancedRecord), reinterpret_cast<char*>(&out_record));
		cout << "int: " << out_record.iValue << " double: "<< out_record.dValue << " float: " << out_record.fValue << endl;
	}
	seb::io::load(filename, 4, sizeof(AdvancedRecord), reinterpret_cast<char*>(&out_record));
	cout << "int: " << out_record.iValue << " double: "<< out_record.dValue << " float: " << out_record.fValue << endl;
	assert( out_record.iValue == 4 && out_record.dValue == 5.11111d && out_record.fValue == 5.22222f );
	remove(filename.c_str());

}

int main(int argc, char* argv[]) {
	testTextFunctions();
	testLinesFunctions();
	testSizeFunctions();
	testLoadStoreFunctions();
	testLoadStoreFunctions2();

	cout << "All test completed." << endl;
	return 0;
}

