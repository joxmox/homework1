#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace NNN {
    using namespace std;

    template<size_t N>
    class text {
        char payload[N];

        size_t last() const {
            size_t k = 0;
            for (; k < N && payload[k]; ++k) { }
            return k;
        }
        
        void pad(size_t pos) {
            for (auto k = pos; k < N; ++k) payload[k] = '\0';
        }

    public:
        constexpr size_t capacity() const { return N; }

        text() { 
            //...what should the default be?
        }

        text(const string& s) {
            //...what to do with s?
        }

        ~text() = default;
        text(const text<N>&) = default;
        text<N>& operator=(const text<N>&) = default;

        string value() const {
            return {payload, payload + last()};
        }

        void value(const string& s) {
            if (s.size() > N) {
                ostringstream buf;
                buf << "text overflow: N=" << N << ", s.size=" << s.size();
                throw out_of_range(buf.str());
            }

            auto pos = s.copy(payload, N);
            if (pos < N) pad(pos);
        }

        operator string() const { 
            //...
        }

        text<N>& operator=(const string& txt) {
            //...
            return *this;
        }
    };

    template<size_t N>
    inline ostream& operator<<(ostream& os, const text<N>& s) {
        //...
    }

    template<size_t N>
    inline istream& operator>>(istream& is, text<N>& s) {
        char buf[N + 1];
        //...read into buf, set null-byte, assign to s
        return is;
    }

    template<size_t N>
    inline bool operator==(const text<N>& left, const text<N>& right) {
        //...
    }

    template<size_t N>
    inline bool operator<(const text<N>& left, const text<N>& right) {
        //...
    }

}
