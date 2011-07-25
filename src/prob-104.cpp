#include <iostream>
#include <boost/lexical_cast.hpp>
#include <gmpxx.h>

bool headZerolessPandigital(const std::string& s) {
    if (s.size() < 9) return false;

    int mask = 0;
    for (int i = 0; i < 9; ++i) mask |= (1 << (s[i] - '0'));
    if (mask != 0x3FE) return false;

    return true;
}

bool tailZerolessPandigital(const std::string& s) {
    if (s.size() < 9) return false;

    int mask = 0;
    for (int i = s.size() - 9; i < s.size(); ++i) mask |= (1 << (s[i] - '0'));
    if (mask != 0x3FE) return false;

    return true;
}

// NOTE: Realizing tail computation being more efficient leads to the solution
int main() {
    mpz_class m;
    int f_n, f_n1 = 1, f_n2 = 1;
    for (int n = 3; ; ++n) {
	f_n = (f_n1 + f_n2) % 1000000000;

	std::string rep = boost::lexical_cast<std::string>(f_n);
	if (tailZerolessPandigital(rep)) {
	    mpz_fib_ui(m.get_mpz_t(), n);
	    if (headZerolessPandigital(m.get_str())) {
		std::cout << n << std::endl;
		break;
	    }
	}

	f_n2 = f_n1;
	f_n1 = f_n;
    }

    return 0;
}
