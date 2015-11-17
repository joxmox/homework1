#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace SEB {
	namespace datatypes {
		using namespace std;
		template<size_t N>
		class integer {
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

			integer(int v) {
				value(v);
			}

			integer() {
				value(0);
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
				return value();
			}

			integer<N>& operator=(int v) {
				value(v);
				return *this;
			}
			integer<N>& operator+=(int value) { this->value(this->value() + value);return *this; }

		};

		template<size_t N>
		inline ostream& operator<<(ostream& os, const integer<N>& s) {
			return os << s.value();
		}

		template<size_t N>
		inline istream& operator>>(istream& is, integer<N>& s) {
			char buf[N + 1];
			is >> buf;
			s = stoi(buf);
			return is;
		}

		template<size_t N>
		inline bool operator==(const integer<N>& left, const integer<N>& right) {
			return left.value() == right.value();
		}

		template<size_t N>
		inline bool operator<(const integer<N>& left, const integer<N>& right) {
			return left.value() < right.value();
		}
	}
}
