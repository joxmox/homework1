/*
 * AccountDBgenerator.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <iostream>
#include <fstream>
#include <unordered_set>
#include "IndexedFile.hpp"
#include "StringUtils.hpp"
#include "GenUtils.hpp"
#include "IOUtils.hpp"
#include "Account.hpp"

using namespace std;
using namespace SEB::db;
using namespace SEB::trans;



std::string nextAccno() {
	static unordered_set<string> used_accno;

	string accno = seb::gen::format("########");

	while (used_accno.count(accno))
		accno = seb::gen::format("########");

	used_accno.insert(accno);

	return accno;
}

int main(int argc, char* argv[])
{
	int N = 10;
	string filename = "accounts.db";
	bool verbose = false;

	for (int k=1; k<argc; ++k) {
		string arg = argv[k];
		if (arg == "-f") {
			filename = argv[++k];
		} else if (arg == "-n") {
			N = stoi(argv[++k]);
		} else if (arg == "-v") {
			verbose = true;
		} else {
			cerr << "usage: "<<argv[0]<<" [-f <filename>] [-n <count>] [-v]\n";
			return 1;
		}
	}

	if (verbose) cout << "Creating " << N << " accounts in DB file " << filename << endl;

	IndexedFile<SEB::trans::Account> db {filename, OpenMode::out};
	for (auto i=0; i<N; i++)
	{
		string newAccno = nextAccno();
		int    newAmount = static_cast<int>( seb::gen::nextNormal(100, 200) );

		Account acc {newAccno, newAmount};
		if (verbose) cout << acc << endl;
		db << acc;
	}

	return 0;
}


