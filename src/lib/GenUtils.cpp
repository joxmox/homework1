/*
 * GenUtils.cpp
 *
 *  Created on: Oct 13, 2015
 *      Author: sebis
 */

#include <vector>
#include <random>
#include <string>

using namespace std;

namespace seb {

	namespace gen {

		string nextString(vector<string> strVec) {
//			default_random_engine r;
			random_device r;
			uniform_int_distribution<> rect(0, strVec.size()-1);
			return strVec[rect(r)];
		}
		string format(string instr) {
			string utstr = "";
			random_device r;
			uniform_int_distribution<> rect(0,9);
			for (unsigned int i=0; i<instr.size();i++){
				if (instr[i] == '#') {
					utstr += to_string(rect(r));
				} else {
					utstr += instr[i];
				}
			}
			return utstr;
		}
		double nextUniform(double lb, double ub) {
			random_device r;
			uniform_int_distribution<> rect(lb, ub);
			return rect(r);
		}
		double nextNormal(double mean, double dev) {
			random_device r;
			normal_distribution<> norm(mean, dev);
			return norm(r);

		}
	}

}





