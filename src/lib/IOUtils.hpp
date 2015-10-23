/*
 * IOUtils.hpp
 *
 *  Created on: Oct 22, 2015
 *      Author: Nisse och Karl
 */

#pragma once

#include <string>
#include <vector>
using namespace std;

namespace seb {
	namespace io {
		extern string text(const string& filename);
		extern void text(const string& filename, const string& content);
		extern vector<string> lines(const string& filename);
		extern void lines(const string& filename, vector<string> content);
		extern int size(const string& filename);
		extern void load(const string& filename, int idx, const int size, char* record);
		extern void store(const string& filename, int idx, const int size, char* record);

	}
}
