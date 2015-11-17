/*
 * Account_test.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <iostream>
#include <Account.hpp>
#include <cassert>

using namespace SEB::trans;

const bool verbose = true;

void createAccountWithValuesShouldWork()
{
	Account acc {"101", 50};
	if (verbose) cout << "With values: " << acc.toString() << endl << acc << endl;;
	assert(acc.getAccno() == "101");
	assert(acc.getBalance() == 50);
}

void createAccountWithCSVShouldWork()
{
	Account acc {"101;55"};
	if (verbose) cout << "With CSV: " << acc.toString() << endl << acc << endl;;
	assert(acc.getAccno() == "101");
	assert(acc.getBalance() == 55);
}

int main()
{
	cout << "Testing accounts" << endl;
	createAccountWithValuesShouldWork();
	createAccountWithCSVShouldWork();

	return 0;
}

