/*
 * TransCSVgen.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */


#include <iostream>
#include "Account.hpp"
#include "IndexedFile.hpp"
#include "GenUtils.hpp"
#include "IOUtils.hpp"
#include "Transaction.hpp"


using namespace SEB::datatypes;
using namespace SEB::db;
using namespace SEB::trans;
using namespace seb::gen;
using namespace seb::io;

using namespace std;


vector<string> loadAccount(const string& filename){

	vector<string> accnos;
	IndexedFile<Account> db {filename, OpenMode::in};
	for(auto  acc : db)
		accnos.push_back(acc.getAccno());

	return accnos;

}

int main(int argc, char* argv[]){

	int N = 10;
		string accountfile = "accounts.db";
		string transfile = "transactions.csv";

		bool verbose = false;

		for (int k=1; k<argc; ++k) {
			string arg = argv[k];
			if (arg == "-f") {
				accountfile = argv[++k];
			} else if (arg == "-csv") {
				transfile = argv[++k];
			} else if (arg == "-n") {
				N = stoi(argv[++k]);
			} else if (arg == "-v") {
				verbose = true;
			} else {
				cerr << "usage: "<<argv[0]<<" [-f <accountfile>] [-n <count>] [-v]\n";
				return 1;
			}
		}

		if (verbose) cout << "Creating " << N << " transactions in a CSV file " << transfile << endl;
		vector<string> accnos = loadAccount(accountfile);

		for(int count=0; count < N; count++)
		{
			Transaction trans;
			trans.setAccno(nextString(accnos));

			trans.setAmount(static_cast<int>( seb::gen::nextNormal(0, 500) ));
			cout<<trans.toCSV()<<endl;
            seb::io::text(transfile, trans.toCSV()+"\n");
		}

	return 0;
}

