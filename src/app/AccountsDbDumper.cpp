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

int main(int argc, char* argv[])
{
	string filename = "accounts.db";
	IndexedFile<SEB::trans::Account> db {filename, OpenMode::in};
	for (auto  acc : db) {
		cout << acc << endl; 
	}
}
