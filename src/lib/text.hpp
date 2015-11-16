#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace SEB {
	namespace datatypes {
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
				pad(0);
			}

			text(const string& s) {
				value(s);
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
				return value();
			}

			text<N>& operator=(const string& txt) {
				value(txt);
				return *this;
			}
		};

		template<size_t N>
		inline ostream& operator<<(ostream& os, const text<N>& s) {
			return os << s.value();

		}

		template<size_t N>
		inline istream& operator>>(istream& is, text<N>& s) {
			char buf[N + 1];
			is >> buf;
			s = buf;
			return is;
		}

		template<size_t N>
		inline bool operator==(const text<N>& left, const text<N>& right) {
			string sLeft = left;
			string sRight = right;
			return sLeft == sRight;
		}

		template<size_t N>
		inline bool operator<(const text<N>& left, const text<N>& right) {
			string sLeft = left;
			string sRight = right;
			return sLeft < sRight;
		}
	}
}
