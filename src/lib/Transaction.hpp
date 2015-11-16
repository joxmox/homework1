/*
 * Transaction.hpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#ifndef SRC_LIB_TRANSACTION_HPP_
#define SRC_LIB_TRANSACTION_HPP_

#include <string>
#include "StringUtils.hpp"

const bool verbose = true;

namespace SEB {
namespace trans {

class Transaction {
	string		accno="";
	int 		amount=0;
	const char	delim=';';

public:
	Transaction();
	Transaction(const string transAccno, const int transAmount);
	Transaction(const string transCSV);
	virtual ~Transaction();

	string toCSV() const;

	const string& getAccno() const {
		return accno;
	}

	int getAmount() const {
		return amount;
	}
};

} /* namespace trans */
} /* namespace SEB */

#endif /* SRC_LIB_TRANSACTION_HPP_ */
