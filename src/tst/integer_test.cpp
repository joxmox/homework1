#include <iostream>
#include <sstream>
#include "integer.hpp"
#include <cassert>
#include <utility>

using namespace std;
using NNN::integer;

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
    //...
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
    //...
}

void out_stream_should_work() {
    //...
}

void in_stream_should_work() {
    //...
}

//...

int main(int numArgs, char* args[]) {
    empty_should_have_value_zero();
    //...

    cout << "All tests passed\n";
    return 0;
}

