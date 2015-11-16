/*
 * Account.hpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#ifndef SRC_LIB_ACCOUNT_HPP_
#define SRC_LIB_ACCOUNT_HPP_

#include <string>
using namespace std;

const bool verbose = true;

namespace SEB {
namespace trans{

class Account {
	string accno="unknown";
	float accbal=0;

public:
	Account();
	Account(const string accno, const float accbal);
	Account(const string csv);
	virtual ~Account();

	void updateBalace(const string updateAccno, const float updateAmount); // Throws exception if not succesful
	string toString() const;
};

ostream& operator <<(ostream& os, const Account& acc);

} /* namespace trans */
} /* namespace SEB */

#endif /* SRC_LIB_ACCOUNT_HPP_ */
