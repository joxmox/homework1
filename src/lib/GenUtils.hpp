/*
 * GenUtils.hpp
 *
 *  Created on: Oct 13, 2015
 *      Author: sebis
 */

#ifndef GENUTILS_HPP_
#define GENUTILS_HPP_

#include <vector>
#include <string>

using namespace std;

namespace seb {

	namespace gen {


	string nextString(vector<string> strVec);
	string format(string pattern);
	double nextNormal(double mean, double dev);
	double nextUniform(double lb, double ub);
	}
}


#endif /* GENUTILS_HPP_ */

/*
 * "Kalle Anka #####-###"
 * "Kalle Anka 16456-545"
 */
