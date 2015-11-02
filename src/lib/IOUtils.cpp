/*
 * IOUtils.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: karl
 */

#include <fstream>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <cstdio>
#include "IOUtils.hpp"
using namespace std;

namespace seb {
	namespace io {
		string text(const string& filename) {
			string result = "";
			ifstream file{filename};
			for(string line; getline(file, line);) {
				result += line;
			}
			return result;
		}
		void text(const string& filename, const string& content) {
			ofstream file(filename);
			file << content;
		}
		vector<string> lines(const string& filename) {
			vector<string> result;
			ifstream file{filename};
			for(string line; getline(file, line);) {
				result.push_back(line);
			}
			return result;
		}
		void lines(const string& filename, vector<string> content) {
			ofstream file(filename);
			for_each(content.begin(), content.end(), [&](string item) { file << item << endl;});
		}

		int size(const string& filename) {
			ifstream file(filename, ios::in | ios::binary);
			file.seekg(0, ios_base::end);
			return file.tellg();
		}
		void load(const string& filename, int idx, const int size, char* record) {
			fstream file(filename, ios_base::in | ios_base::binary);
			file.seekg(idx * size);
			file.read(record, size);
		}

		void store_old(const string& filename, int idx, const int size, char* record) {
			int filesize = seb::io::size(filename);
			if(filesize < (idx * size)) {
				cout << "resizing" <<endl;
				truncate(filename.c_str(), (idx*size));
			}
			fstream file(filename,  ios_base::out | ios_base::binary );

			int index = idx * size;
			file.seekp(index);

			if (file.fail()) cout << "FAIL!!! setting index to " << index << endl;
			cout << "Index is " << file.tellp() << endl;
			file.write(record, size);
			file.flush();
		}
		void store(const string& filename, int idx, const int size, char* record) {
			// first create file if it doesnt exist...
			FILE* pFile = fopen(filename.c_str(), "a");
			if(!pFile) {
				//failed to open file
				cerr << "Failed to open file " << filename << endl;
				return;
			}
			fclose(pFile);
			pFile = fopen(filename.c_str(), "r+");
			int writePos = idx * size;
			if( pFile ) {
				if(fseek(pFile, writePos, SEEK_SET) == 0) {
					fwrite(record, size, 1, pFile);
				}
				fclose(pFile);
			}
		}
	}
}


