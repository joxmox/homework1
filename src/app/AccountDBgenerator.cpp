/*
 * AccountDBgenerator.cpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#include <iostream>
#include <fstream>
#include "IndexedFile.hpp"
#include "StringUtils.hpp"
#include "GenUtils.hpp"
#include "IOUtils.hpp"
#include "Account.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	int N = 10;
	string filename = "accounts.db";
	if (argc > 1) filename = argv[1];
	if (argc > 2) N = stoi(argv[2]);
	if (verbose) cout << "Creating " << N << " accounts in DB file " << filename << endl;

	SEB::db::IndexedFile<SEB::trans::Account> db {filename, SEB::db::OpenMode::out};

	for (auto i=0; i<N; i++)
	{
		string newAccno = seb::gen::format("#####");
		int newAmount = seb::gen::nextNormal(500, 200);
		if (verbose) cout << "Account: " << newAccno << ", amount: " << newAmount << endl;
		SEB::trans::Account acc {newAccno, newAmount};
		db << acc;

	}

	return 0;
}


