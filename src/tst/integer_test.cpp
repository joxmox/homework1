#include <iostream>
#include <sstream>
#include "integer.hpp"
#include <cassert>
#include <utility>

using namespace std;
using SEB::datatypes::integer;

void empty_should_have_value_zero() {
    integer<4> n;
    assert(n.capacity() == 4);
    assert(n.value() == 0);
}

void initialization_should_work() {
    integer<4> n{42};
    assert(n.value() == 42);
}

void assignment_should_work() {
    integer<4> n;
    n = 5;
    assert (n.value() == 5);
}

void overflow_should_throw() {
    integer<2> n;
    assert(n.value() == 0);

    try {
        n = 123;
        assert(false);
    } catch (out_of_range& x) {
        assert(string(x.what()).substr(0, 11) == "value(int):");
    }
}

void relops_should_work() {
    integer<4> n1{10};
    integer<4> n2{10};
    assert(n1 == n2);
    n1 = 5;
    assert(n1 < n2);
}

void out_stream_should_work() {
    integer<8> t{1234};
    ostringstream buf;
    buf << t;
    assert(buf.str() == "1234");
}

void in_stream_should_work() {
	integer<4> n;
	assert(n.value() == 0);

	istringstream buf{"1234"};
	buf >> n;
	assert(n.capacity() == 4);
	assert(n.value() == 1234);
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

