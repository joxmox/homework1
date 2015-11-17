#include <string>
#include <stdexcept>
#include <iomanip>
#include <cmath>
namespace SEB {
	namespace datatypes {
		using namespace std;

		template<size_t N, unsigned short D>
		class real {
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

		real() {
			value(0);
		}
		real(float v) {
			value(v);
		}

		float value() const {
			string s{payload, payload + last()};
			return stof(s);
		}
		void value(float v) {
			ostringstream buf;
			buf << fixed << setprecision(D) << v;
			string s = buf.str();
			if (s.size() > N) {
				throw out_of_range("value(float): too many chars=" + s);
			}
			auto pos = s.copy(payload, N);
			if (pos < N) pad(pos);
		}

		operator float() const {return value();}
		real<N,D>&  operator=(float v) {value(v); return *this;}

		//...
		};

		template<size_t N, unsigned short D>
		inline ostream& operator<<(ostream& os, const real<N,D>& s) {
			return os << s.value();
		}

		template<size_t N, unsigned short D>
		inline istream& operator>>(istream& is, real<N,D>& s) {
			char buf[N + 1];
			is >> buf;
			s = stof(buf);
			return is;
		}

		template<size_t N, unsigned short D>
		inline bool operator==(const real<N,D>& left, const real<N,D>& right) {
			return abs(left.value() - right.value()) < 0.000001;
		}

		template<size_t N, unsigned short D>
		inline bool operator<(const real<N,D>& left, const real<N,D>& right) {
			return left.value() <  right.value();
		}
	}
}

