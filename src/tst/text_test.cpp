#include <iostream>
#include <sstream>
#include "text.hpp"
#include <cassert>

using namespace std;
using NNN::text;

void empty_text4_should_have_capacity_4_but_zero_size() {
    text<4> t;
    assert(t.capacity() == 4);
    assert(t.value().size() == 0);
}

void half_full_text_should_have_size_half_of_capacity() {
    text<8> t{"abcd"};
    assert(t.capacity() == 8);
    assert(t.value().size() == 4);
    assert(t.value() == "abcd");
}

void type_conversions_should_work() {
    text<8> t{"abcd"};
    string s = t;
    assert(s == "abcd");
    t = "12345678";
    assert(t.value() == "12345678");
}

void assigning_too_long_string_should_throw() {
    text<3> t{"abc"};
    try {
        t = "abcd";
        assert(false);
    } catch (out_of_range& x) {
        assert(string(x.what()).find("overflow:") > 0);
    }
}

void out_stream_should_work() {
    text<8> t{"abcd"};
    ostringstream buf;
    buf << t;
    assert(buf.str() == "abcd");
}

void in_stream_with_full_payload_should_work() {
    text<4> t;
    assert(t.value().size() == 0);

    istringstream buf{"abcd"};
    buf >> t;
    assert(t.capacity() == 4);
    assert(t.value().size() == 4);
    assert(t.value() == "abcd");
}

void in_stream_with_half_payload_should_work() {
    //...
}

void in_stream_with_double_payload_should_work() {
    //...
}

void equal_op_should_work() {
    //...
}

void less_than_op_should_work() {
    //...
}

//...

int main(int numArgs, char* args[]) {
    empty_text4_should_have_capacity_4_but_zero_size();
    //...

    cout << "All tests passed\n";
    return 0;
}

