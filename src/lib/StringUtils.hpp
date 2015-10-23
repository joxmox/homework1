/*
 * StringUtils.hpp
 *
 *  Created on: Oct 22, 2015
 *      Author: Stefan, Mehran och Thomas
 */

#ifndef STRINGUTILS_HPP_
#define STRINGUTILS_HPP_

#include <string>
#include <vector>

using namespace std;

namespace seb {
  namespace str {
     string 		lowercase	(const string& s);
     string 		uppercase	(const string& s);
     string 		truncate	(const string& s, const int w);
     string 		left		(const string& s, const int w, const char p);
     string 		right		(const string& s, const int w, const char p);
     string 		center		(const string& s, const int w, const char p);
     vector<string> split		(const string& s, const char delim);
     string 		join		(const vector<string>& v, const char sep);
  }
}

#endif /* STRINGUTILS_HPP_ */
