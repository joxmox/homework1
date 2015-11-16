#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

namespace SEB {
	namespace datatypes {
		using namespace std;


		class boolean {
			char  payload;
			constexpr static char FALSE = 'F';
			constexpr static char TRUE  = 'T';

		  public:
			boolean() { payload = FALSE; }
			boolean(bool v)  {
				value(v);
			}

			bool value() const {
				return payload == TRUE;
			}
			void value(bool v) {
				payload = (v ? TRUE : FALSE);
			}

			operator bool() const {return value();}
			boolean&  operator=(bool v) {value(v); return *this;}

		};
		inline ostream& operator<<(ostream& os, const boolean& s) {
			return os << (s.value() ? "T": "F");
		}

		inline istream& operator>>(istream& is, boolean& s) {
			char buf;
			is >> buf;
			s = buf;
			return is;
		}

		inline bool operator==(const boolean& left, const boolean& right) {
			bool bLeft = left;
			bool bRight = right;
			return bLeft == bRight;
		}

		inline bool operator<(const boolean& left, const boolean& right) {
			bool bLeft = left;
			bool bRight = right;
			return bLeft < bRight;
		}
	}
}


