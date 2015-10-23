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

int main2(int argc, char* argv[]) {
	testTextFunctions();
	testLinesFunctions();
	testSizeFunctions();
	testLoadStoreFunctions();


	cout << "All test completed." << endl;
	return 0;
}

