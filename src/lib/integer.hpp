#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace NNN {
    using namespace std;

    template<size_t N>
    class integer {
        char payload[N];

        size_t last() const {
            //...same as for text<N>
        }

        void pad(size_t pos) {
            //...same as for text<N>
        }

    public:
        constexpr size_t capacity() const { return N; }

        integer(int v) {
            //...
        }

        integer() {
            //...
        }

        ~integer() = default;
        integer(const integer<N>&) = default;
        integer<N>& operator=(const integer<N>&) = default;

        int value() const {
            string s{payload, payload + last()};
            return stoi(s);
        }

        void value(int v) {
            string s = to_string(v);
            if (s.size() > N) {
                throw out_of_range("value(int): too many chars=" + s);
            }
            auto pos = s.copy(payload, N);
            if (pos < N) pad(pos);
        }

        operator int() const { 
            //...
        }

        integer<N>& operator=(int v) {
            //...
            return *this;
        }
    };

    template<size_t N>
    inline ostream& operator<<(ostream& os, const integer<N>& s) {
        //...
    }

    template<size_t N>
    inline istream& operator>>(istream& is, integer<N>& s) {
        //...
        return is;
    }

    template<size_t N>
    inline bool operator==(const integer<N>& left, const integer<N>& right) {
        //...
    }

    template<size_t N>
    inline bool operator<(const integer<N>& left, const integer<N>& right) {
        //...
    }
    
}
