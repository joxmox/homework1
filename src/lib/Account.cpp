/*
 * Account.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <iostream>
#include <Account.hpp>

namespace SEB {
namespace trans {

Account::Account() {
	// TODO Auto-generated constructor stub

}

Account::Account(const string newAccno, const float newAccbal)
{
	accno = newAccno;
	accbal = newAccbal;

	if (verbose) cout << "Creating Account with values" << endl;

}
Account::Account(const string csv) {
	// TODO

}

Account::~Account() {
	// TODO Auto-generated destructor stub
	if (verbose) cout << "terminating Account" << endl;
}

string Account::toString() const
{
	return "Account: " + accno + ", balance: " + to_string(accbal);
}

ostream& operator <<(ostream& os, const Account& acc)
{
	return os << acc.toString();
}

} /* namespace trans */
} /* namespace SEB */
