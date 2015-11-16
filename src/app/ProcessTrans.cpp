/*
 * ProcessTrans.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <string>
#include "lineSlurper.hpp"
#include "Account.hpp"
#include "Transaction.hpp"
#include "IndexedFile.hpp"

using namespace std;
using namespace SEB::trans;
using namespace seb::str;
using namespace SEB::db;

int main(int argc, char* argv[]) {
	string dbName = "accounts.db";
	string transName = "trans.dat";
	bool verbose = true;

	for (int k = 1; k < argc; ++k) {
		string arg = argv[k];
		if (arg == "-a") {
			dbName = argv[++k];
		} else if (arg == "-t") {
			transName = stoi(argv[++k]);
		} else if (arg == "-v") {
			verbose = true;
		} else {
			cerr << "usage: " << argv[0]
					<< " [-a <dbfile>] [-t <transfile>] [-v]\n";
			return 1;
		}
	}

	IndexedFile<Account> db {dbName, OpenMode::inout};
	LineSlurper lsp {transName};

	for (auto line : lsp) {
		if (verbose) cout << "Read transaction line: " << line << endl;
		Transaction t { line };
		Account a = db[t.getAccno()];
		if (verbose) cout << "Account: " << a.getAccno() << ", old bal: " << a.getBalance();
		a.updateBalance(t.getAmount());
		if (verbose) cout << ", new bal: " << a.getBalance() << endl;
		db[t.getAccno()] = a;
	}
}

