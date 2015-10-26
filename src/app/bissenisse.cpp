/*
 * Bissenisse.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: sebis
 */

#include <iostream>
#include <string>
#include "GenUtils.hpp"
#include "IOUtils.hpp"
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Account {
	unsigned accno;
	double balance;
	float rate;
};


Account generateAccount() {
	static unsigned nextAccNo = 1;
	double newBalance = seb::gen::nextNormal(10000, 10000);
	float newRate = seb::gen::nextUniform(0.002, 0.035);
	return {nextAccNo++, newBalance, newRate};
}

void printAcc(const Account& acc) {
	cout << "Account no: " << acc.accno << ", Balance: $" <<
			 fixed << setprecision(2)<<  acc.balance << ", Rate: " <<
			 fixed << setprecision(1) <<  acc.rate*100 << "%" << endl;
}

int main(int argc, char* argv[]) {
	int N {10};
	string fileName {"build/accounts.dat"};
	bool quiet = false;

	for (auto i=1; i<argc; i++) {
		string arg = argv[i];
		if (arg == "-n") {
			N = stoi(argv[++i]);
		} else if (arg == "-f") {
			fileName = argv[++i];
		} else if (arg == "-q") {
			quiet = true;
		} else {
			cout << "Usage: " << argv[0] << " [-f <filename>] [-n <numberofaccs>]" << endl;
			return 1;
		}
	}

	string cmd = "rm -f " + fileName;
	system(cmd.c_str());

	double balSum1 {0};
	for (auto i=0; i<N; i++) {
		Account newAcc = generateAccount();
		if (!quiet) printAcc(newAcc);
		balSum1 += newAcc.balance;
		seb::io::store(fileName, i, sizeof(Account), reinterpret_cast<char*>(&newAcc));
	}
	cout << "Account balance sum(1) = " <<  fixed  << setprecision(2) <<  balSum1 << endl;
	cout << "Written " << N << " records to " << fileName << endl << endl;
    double balSum2 {0};
    for (auto i=0; i<N; i++) {
    	Account oldAcc;
    	seb::io::load(fileName, i, sizeof(Account), reinterpret_cast<char*>(&oldAcc));
    	balSum2 += oldAcc.balance;
    	if (!quiet) printAcc(oldAcc);
    }
    cout << "Read " << N << " records from " << fileName << endl;
    cout << "Account balance sum(2) = " <<  fixed  << setprecision(2) << balSum2 << endl << endl;
    if (balSum1 == balSum2)  {
    	cout << "Account sums are equal!" << endl;
    } else {
    	cout << "Account sums are NOT equal!" << endl;
    }
	return 0;
}
