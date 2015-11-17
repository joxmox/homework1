/*
 * Account.hpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#ifndef SRC_LIB_ACCOUNT_HPP_
#define SRC_LIB_ACCOUNT_HPP_

#include <string>
#include "text.hpp"
#include "integer.hpp"

using namespace std;


namespace SEB {
namespace trans{

using namespace SEB::datatypes;

class Account {
	text<8> accno;
	integer<8> accbal;

public:
	Account();
	Account(const string accno, const int accbal);
	Account(const string csv);
	virtual ~Account();

	int getBalance() const {return accbal.value();}
	string getAccno() const {return accno.value();}
	void updateBalance(const int); // Throws exception if not succesfull
	string toString() const;

	const integer<8>& getAccbal() const {
		return accbal;
	}

	const text<8>& getAccno() const {
		return accno;
	}
	string indexKey() {
		return accno;
	}
};

ostream& operator <<(ostream& os, const Account& acc);

} /* namespace trans */
} /* namespace SEB */

#endif /* SRC_LIB_ACCOUNT_HPP_ */
