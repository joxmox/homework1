#include <iostream>
#include "IndexedFile.hpp"
#include "Account.hpp"

using namespace std;
using namespace SEB::db;
using namespace SEB::trans;

int main(int argc, char* argv[])
{
	string filename = "accounts.db";
	for( int idx = 1; idx< argc; ++idx)
	{
		string arg = argv[idx];
		if (arg == "-f" ) {
			filename = argv[++idx];
		} else {
			cerr << "usage: "<<argv[0]<<" [-f <filename>] \n";
			return 1;
		}
	}
	IndexedFile<SEB::trans::Account> db {filename, OpenMode::in};
	for (auto  acc : db) {
		cout << acc << endl; 
	}
}
