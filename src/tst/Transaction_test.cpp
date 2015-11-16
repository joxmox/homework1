/*
 * Transaction_test.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <string>
#include <cassert>
#include <iostream>
#include <Transaction.hpp>

using namespace SEB::trans;

void toCSVshouldWork()
{
	if (verbose) cout << "toCSVshouldWork" << endl;
	Transaction t {"123", 12};
	if (verbose) cout << "CSV string: " << t.toCSV() << endl;
	assert(t.toCSV() == "123;12");
}

void constructorCSVshouldWork()
{
	if (verbose) cout << "constructorCSVshouldWork" << endl;
	Transaction t {"456;45"};
	assert(t.getAccno() == "456");
	assert(t.getAmount() == 45);

	if (verbose) cout << "Account: " << t.getAccno() << ", amount: " << t.getAmount() << endl;
}

int main()
{
	cout << "Testing Transaction begins" << endl;
	toCSVshouldWork();
	constructorCSVshouldWork();

	cout << "Testing Transaction done" << endl;
	return 0;
}
