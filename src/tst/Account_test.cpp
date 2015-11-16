/*
 * Account_test.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <iostream>
#include <Account.hpp>

using namespace SEB::trans;

void createAccountShouldWork()
{
	Account acc {"101", 50.5};
	if (verbose) cout << acc.toString() << endl << acc << endl;;
	Account acc_csv {"101;55,1"};
	if (verbose) cout << acc_csv.toString() << endl << acc_csv << endl;;
}

int main()
{
	cout << "Testing accounts" << endl;
	createAccountShouldWork();

	return 0;
}

