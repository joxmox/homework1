#include <iostream>
#include <sstream>
#include "real.hpp"
#include <cassert>
#include <utility>
#include <cmath>

using namespace std;
using SEB::datatypes::real;

bool eqfloat(float a1, float a2) {
	return abs(a1-a2) < 0.00001;
}


void empty_should_have_value_zero() {
    real<4,1> n;
    assert(n.capacity() == 4);
    assert(n.value() == 0);
}

void initialization_should_work() {
    real<4,1> n{42.1};
    assert(eqfloat(n.value() , 42.1));
}

void assignment_should_work() {
    real<4,1> n;
    n = 5.1;
    assert (eqfloat(n.value(),5.1));
}

void overflow_should_throw() {
    real<3,1> n;
    assert(n.value() == 0);

    try {
        n = 123.1;
        assert(false);
    } catch (out_of_range& x) {
        assert(string(x.what()).substr(0, 13) == "value(float):");
    }
}

void relops_should_work() {
    real<4,1> n1{10.1};
    real<4,1> n2{10.1};
    assert(n1 == n2);
    n1 = 5.1;
    assert(n1 < n2);
}

void out_stream_should_work() {
    real<8,1> t{1234.1};
    ostringstream buf;
    buf << t;
    assert(buf.str() == "1234.1");
}

void in_stream_should_work() {
	real<4,1> n;
	assert(n.value() == 0);

	istringstream buf{"12.1"};
	buf >> n;
	assert(n.capacity() == 4);
    assert(eqfloat(n.value() , 12.1));
}



int main(int numArgs, char* args[]) {
    empty_should_have_value_zero();
    initialization_should_work();
    assignment_should_work();
    overflow_should_throw();
    relops_should_work();
    out_stream_should_work();
    in_stream_should_work();

    cout << "All tests passed\n";
    return 0;
}

