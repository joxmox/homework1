/*
 * Transaction.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <string>
#include <iostream>
#include <sstream>
#include <Transaction.hpp>
#include "StringUtils.hpp"

namespace SEB {
namespace trans {

using namespace std;

Transaction::Transaction() {
	// TODO Auto-generated constructor stub

}

Transaction::Transaction(const string transAccno, const int transAmount)
{
	accno = transAccno;
	amount = transAmount;
}

Transaction::Transaction(const string transCSV)
{
	vector<string> v = seb::str::split(transCSV, delim);

	accno = v[0];
	amount = stoi(v[1]);
}

Transaction::~Transaction() {
	// TODO Auto-generated destructor stub
}

string Transaction::toCSV() const
{
	vector<string> v {accno, to_string(amount)};

	return seb::str::join(v, delim);
}

} /* namespace trans */
} /* namespace SEB */
