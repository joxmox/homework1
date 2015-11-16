#include <iostream>
#include <sstream>
#include "text.hpp"
#include <cassert>

using namespace std;
using SEB::text;

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
    text<8> t;
    assert(t.value().size() == 0);

    istringstream buf{"abcd"};
    buf >> t;
    assert(t.capacity() == 8);
    assert(t.value().size() == 4);
    assert(t.value() == "abcd");
}

void in_stream_with_double_payload_should_work() {
    text<4> t;
    assert(t.value().size() == 0);

    istringstream buf{"abcdefgh"};
    buf >> t;
    assert(t.capacity() == 4);
    assert(t.value().size() == 4);
    assert(t.value() == "abcd");
}

void equal_op_should_work() {
	text<4> t1 {"abcd"};
	text<4> t2 {"abcd"};

	assert( t1 == t2 );
}

void less_than_op_should_work() {
	text<4> t1 {"abcd"};
	text<4> t2 {"efgh"};

	assert( t1 < t2 );
}

//...

int main(int numArgs, char* args[]) {
    empty_text4_should_have_capacity_4_but_zero_size();
    half_full_text_should_have_size_half_of_capacity();
    type_conversions_should_work();
    assigning_too_long_string_should_throw();
    out_stream_should_work();
    in_stream_with_full_payload_should_work();
    cout << "All tests passed\n";
    return 0;
}

