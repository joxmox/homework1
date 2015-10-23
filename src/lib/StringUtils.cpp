/*
 * StringUtils.cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: Stefan, Mehran och Thomas
 */

#include <cctype>
#include <iostream>
#include <sstream>
#include "StringUtils.hpp"

using namespace std;

namespace seb {
  namespace str {
     string lowercase (const string& s)
     {
         string    r;

         for (auto ch : s)
        	 r += ::tolower(ch);

         return r;
     }

     string uppercase (const string& s)
     {
    	     string    r;

    	      for (auto ch : s)
    	    	  r += ::toupper(ch);

    	      return r;
     }

     string truncate (const string& s, const int w)
     {
    	 return s.substr(0, w);
     }

     string left (const string& s, const int w, const char p)
     {
    	 return (s.length() >= w) ? truncate(s, w) : s + string(w-s.length(), p);

     }

     string right (const string& s, const int w, const char p)
     {
    	 return (s.length() >= w) ? s.substr(s.length()-w, s.length()) : string(w-s.length(), p) + s;
     }

     string pad_around_string (const string& s, const int w, const char p)
     {
    	 return (string((w-s.length()+1)/2, 'P') + s + string((w-s.length())/2, 'P'));
     }

     string center (const string& s, const int w, const char p)
     {
    	 return (s.length() >= w) ? s.substr((s.length()-w)/2,w) : pad_around_string(s, w, p);
     }

     vector<string> split (const string& s, const char delim)
	{
    	 vector<string> internal;
    	 stringstream tmp(s);
    	 string tok;

    	 while (getline(tmp, tok, delim))
    		 internal.push_back(tok);

    	 return internal;
    }

     string join (const vector<string>& v, const char sep)
     {
    	 string tmp = "";

    	 for (auto s : v) tmp = tmp + s + sep;

    	 return left(tmp, tmp.length()-1, ' ');
     }
  }
}
