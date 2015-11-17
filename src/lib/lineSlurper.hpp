/*
 * lineSlurper.hpp
 *
 *  Created on: Nov 16, 2015
 *      Author: sebis
 */

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

class LineSlurper {
    ifstream file;

public:
    LineSlurper(const string& filename) : file(filename) {
        if (!file) throw invalid_argument("cannot open " + filename);
    }

    class iterator {
        ifstream&   file;
        bool        eof;
        string      currentLine;

        string readLine() {
            string line;
            getline(file, line);
            eof = !file.good();
            return line;
        }

    public:
        iterator(ifstream& file, bool eof) : file(file), eof(eof) {
            if (!eof) currentLine = readLine();
        }

        bool operator!=(const iterator& that) {return (*this).eof != that.eof;}

        string operator*() {return currentLine;}

        iterator& operator++() {
            currentLine = readLine();
            return *this;
        }
    };

    iterator begin() {return iterator(file, false);}

    iterator end() {return iterator(file, true);}
};

