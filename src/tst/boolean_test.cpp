#include <iostream>
#include <sstream>
#include "boolean.hpp"
#include <cassert>
#include <utility>

using namespace std;
using SEB::datatypes::boolean;

void empty_should_have_value_false() {
    boolean n;
    assert(n.value() == false);
}

void initialization_should_work() {
    boolean n{true};
    assert(n.value() == true);
}

void assignment_should_work() {
    boolean n;
    n = true;
    assert (n.value() == true);
}


void relops_should_work() {
    boolean n1{true};
    boolean n2{true};
    assert(n1 == n2);
    n1 = false;
    assert(n1 < n2);
}

void out_stream_should_work() {
    boolean t{true};
    ostringstream buf;
    buf << t;
    assert(buf.str() == "T");
}

void in_stream_should_work() {
	boolean n;
	assert(n.value() == false);

	istringstream buf{"T"};
	buf >> n;
	assert(n.value() == true);
}



int main(int numArgs, char* args[]) {
	empty_should_have_value_false();
    initialization_should_work();
    assignment_should_work();
    relops_should_work();
    out_stream_should_work();
    in_stream_should_work();

    cout << "All tests passed\n";
    return 0;
}

