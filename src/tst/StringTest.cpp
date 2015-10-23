/* * StringTest.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: Mehran, Stefan och Thomas
 */

#include <iostream>
#include <cassert>
#include "StringUtils.hpp"

using namespace std;
using namespace seb::str;

const bool verbose = true;

void lowercase_should_work()
{
	cout << "Testar funktionen lowercase" << endl;
	if (verbose) cout << "abcABC123_+ -> " << lowercase("abcABC123_+") << endl << endl;
	assert(lowercase("abcABC123_+") == "abcabc123_+");
}

void uppercase_should_work()
{
	cout << "Testar funktionen uppercase" << endl;
	if (verbose) cout << "abcABC123_+ -> " << uppercase("abcABC123_+") << endl << endl;
	assert(uppercase("abcABC123_+") == "ABCABC123_+");
}

void truncate_should_work()
{
	cout << "Testar funktionen truncate" << endl;
	if (verbose) cout << "abcABC123_+(5) -> " << truncate("abcABC123_+", 5) << endl;
	assert(truncate("abcABC123_+", 5) == "abcAB");
	if (verbose) cout << "abcABC123_+(20) -> " << truncate("abcABC123_+", 20) << endl;
	assert(truncate("abcABC123_+", 20) == "abcABC123_+");
	if (verbose) cout << "abcABC123_+(-5) -> " << truncate("abcABC123_+", -5) << endl << endl;
	assert(truncate("abcABC123_+", -5) == "abcABC123_+");
}

void left_should_work()
{
	cout << "Testar funktionen left" << endl;
	if (verbose) cout << "abcABC123_+(5) -> " << left("abcABC123_+", 5, 'P') << endl;
	assert(left("abcABC123_+", 5, 'P') == "abcAB");
	if (verbose) cout << "abcABC123_+(15)-> " << left("abcABC123_+", 15, 'P') << endl;
	assert(left("abcABC123_+", 15, 'P') == "abcABC123_+PPPP");
	if (verbose) cout << "abcABC123_+(0)-> " << left("abcABC123_+", 0, 'P') << endl << endl;
	assert(left("abcABC123_+", 0, 'P') == "");
}

void right_should_work()
{
	cout << "Testar funktionen right" << endl;
	if (verbose) cout << "abcABC123_+(5) -> " << right("abcABC123_+", 5, 'P') << endl;
	assert(right("abcABC123_+", 5, 'P') == "123_+");
	if (verbose) cout << "abcABC123_+(15)-> " << right("abcABC123_+", 15, 'P') << endl << endl;
	assert(right("abcABC123_+", 15, 'P') == "PPPPabcABC123_+");
}

void center_should_work()
{
	cout << "Testar funktionen center" << endl;
	if (verbose) cout << "abcde(3) -> " << center("abcde", 3, 'P') << endl;
	assert(center("abcde", 3, 'P') == "bcd");
	if (verbose) cout << "abcde(5) -> " << center("abcde", 5, 'P') << endl;
	assert(center("abcde", 5, 'P') == "abcde");
	if (verbose) cout << "abcde(9) -> " << center("abcde", 9, 'P') << endl;
	assert(center("abcde", 9, 'P') == "PPabcdePP");
	if (verbose) cout << "abcde(8) -> " << center("abcde", 8, 'P') << endl << endl;
	assert(center("abcde", 8, 'P') == "PPabcdeP");
}

void split_should_work()
{
	vector<string> expected =  {"Mehran","Stefan","Thomas"};
	vector<string> expected2 = {"Alla ord utan avgränsare"};

	cout << "Testar funktionen split" << endl;
	if (verbose)
	{
		cout << "Mehran,Stefan,Thomas" << endl;
		for (auto s : split("Mehran,Stefan,Thomas", ',')) cout << ":" << s << endl;
		cout << "Alla ord utan avgränsare" << endl;
		for (auto s : split("Alla ord utan avgränsare", ',')) cout << ":" << s << endl;
		cout << ",börjar,med,en,avgränsare," << endl;
		for (auto s : split(",börjar,med,en,avgränsare", ',')) cout << ":" << s << endl;
		cout << endl;
	}
	assert(split("Mehran,Stefan,Thomas", ',') == expected);
}

void join_should_work()
{
	vector<string> payload = {"Mehran","Stefan","Thomas"};

	cout << "Testar funktionen join" << endl;
	if (verbose) cout << "Mehran,Stefan,Thomas -> " << join(payload, ',') << endl << endl;
	assert(join(payload, ',') == "Mehran,Stefan,Thomas");
}

int main()
{
	cout << "Testar våra stringfunktioner" << endl << endl;
	lowercase_should_work();
	uppercase_should_work();
	truncate_should_work();
	left_should_work();
	right_should_work();
	center_should_work();
	split_should_work();
	join_should_work();
	cout << "Alla tester klara" << endl;

	return 0;
}
