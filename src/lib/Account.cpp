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
	accno="";
	accbal = 0;
}

Account::Account(const string newAccno, const int newAccbal)
{
	accno = newAccno;
	accbal = newAccbal;
}
Account::Account(const string csv) {
	// TODO

}

Account::~Account() {
	// TODO Auto-generated destructor stub
}

string Account::toString() const
{
	return "Account: " + accno.value() + ", balance: " + to_string(accbal.value());
}

void Account::updateBalance(const int amt) {
	//accbal += amt; waiting for karl
	accbal.value(accbal.value() + amt);
}

ostream& operator <<(ostream& os, const Account& acc)
{
	return os << acc.toString();
}

} /* namespace trans */
} /* namespace SEB */
