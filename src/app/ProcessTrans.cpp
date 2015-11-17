/*
 * ProcessTrans.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
#include "lineSlurper.hpp"
#include "Account.hpp"
#include "Transaction.hpp"
#include "IndexedFile.hpp"

using namespace std;
using namespace SEB::trans;
using namespace SEB::db;

int main(int argc, char* argv[]) {
	string dbName = "accounts.db";
	string transName = "trans.dat";
	bool verbose = false;

	for (int k = 1; k < argc; ++k) {
		string arg = argv[k];
		if (arg == "-a") {
			dbName = argv[++k];
		} else if (arg == "-t") {
			transName = argv[++k];
		} else if (arg == "-v") {
			verbose = true;
		} else {
			cerr << "usage: " << argv[0] << " [-a <dbfile>] [-t <transfile>] [-v]" << endl;
			return 1;
		}
	}

	try {
	    IndexedFile<Account> db {dbName, OpenMode::inout};
		vector<string> errorMess;
		bool anyProcessed = false;
		try {
			for (auto line : LineSlurper {transName}) {
				Transaction t {line};
				try {
					string accno = t.getAccno();
					int amt = t.getAmount();
					Account a = db[accno];
					if (!anyProcessed) {
						anyProcessed = true;
						if (verbose) {
							cout << setw(10) << right << "Account" << setw(8) << "Amount" << setw(12) << "Balance in" << setw(13) << "Balance out" << setw(8) << left << "  Status" << endl;
						}
					}
					if (verbose) cout << right << setw(10) << accno << setw(8) << amt << setw(12) << a.getBalance();
					a.updateBalance(amt);
					if (verbose) cout << setw(13) << a.getBalance();
					db[accno] = a;
					Account b = db[accno];
					if (accno == "10076488") b.updateBalance(1);  // Just to fake one specific transaction to fail
					if (b.getBalance() == a.getBalance()) {
						if (verbose) cout << setw(8) << left << "  [OK]" << endl;
					} else {
						if (verbose) cout << setw(8) << left << "  [Error]" << endl;
						ostringstream os;
						os << "Error:   Account " << accno << " - New balance is " << b.getBalance() << ", should be " << a.getBalance();
						errorMess.push_back(os.str());
					}
				} catch (out_of_range& err) {
					if (string(err.what()).substr(0, 8) == "no index") {
						ostringstream os;
						os << "Warning: Account " << t.getAccno() << " - Does not exist in database - skipping";
						errorMess.push_back(os.str());
					} else {
						throw err;
					}
				}
			}

			if (!anyProcessed) errorMess.push_back("Warning: No transactions processed");

			if (!errorMess.empty()) {
				cerr << "The following problems were encountered during processing:" << endl;
				for (auto e : errorMess) {
					cout << "  " << e << endl;
				}
			}

		} catch (invalid_argument &err) {
			cerr << "Error: cannot open transactions file: " << transName << endl;
			return 1;
		}

	} catch (invalid_argument& err) {
		cerr << "Error: cannot open accounts database: " << dbName << endl;
		return 1;
	}

}
