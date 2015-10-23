/*
 * GenTest.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: sebis
 */

#include <string>
#include <cassert>
#include <vector>
#include <iostream>
#include "GenUtils.hpp"
#include <cctype>
#include <cmath>

using namespace std;
using namespace seb::gen;

void testNextString() {
	vector<string> testVec {"Roger", "Åsa", "Jocke", "Evert", "Apan"};
	string retStr = nextString(testVec);
	bool found = false;
	for (auto s : testVec) {
		if (s == retStr) found = true;
	}
	assert(found == true);
	cout << "nextString tested" << endl;
	cout << "str:" << retStr << endl;
}

void testFormat() {
	string instr {"ABC###"};
	string utstr = format(instr);
	assert(instr.size() == utstr.size());
	for (unsigned int i=0; i<instr.size();i++){
		if (instr[i] == '#') {
			assert(isdigit(utstr[i]));
		} else {
			assert(utstr[i] == instr[i]);
		}
	}
	cout << "Format ok..." << endl;
}

void testUniform(){
	double low, upper, result;
	low = 2;
	upper = 100;
	result = nextUniform(low, upper);
	assert(result >=low && result <=upper);
	cout << "Uniform ok" << endl;
	cout << "Result blev:" << result << endl;
}


void testnextNormal () {
	double eps = 0.1;
	double mean, dev, result, summa;
	const int iter = 10000;
	mean = 100;
	dev = 2;
	for (int i = 1; i <= iter; i++) {
		summa += nextNormal(mean, dev);
	}
	result = summa/iter;
	assert(abs(result - mean) < eps);

	cout << "nextNormal test" << endl;
	cout << "Result blev nu: " << result << endl;
}

int main() {
	testNextString();
	testFormat();
	testUniform();
	testnextNormal();
}

