#include <cmath>
#include <iostream>
#include <gmpxx.h>

#include "ContinuedFraction.hpp"

// NOTE: I got stuck for two days while bruteforcing my way out.
//
// Courtesy of http://mukeshiiitm.wordpress.com/2011/02/11/project-euler-problem-100/
int main() {
    mpz_class N;
    mpz_ui_pow_ui(N.get_mpz_t(), 10, 12);

    ContinuedFraction fraction(8);

    for (int n = 1; ; ++n) {
	mpq_class c = fraction.getConvergent(n);

	mpz_class x2, r2;
	mpz_pow_ui(x2.get_mpz_t(), c.get_num().get_mpz_t(), 2);
	mpz_pow_ui(r2.get_mpz_t(), c.get_den().get_mpz_t(), 2);

	if (x2 - 8 * r2 == 1) {
	    mpz_class result = 2 * c.get_den() + (c.get_num() + 1) / 2;
	    if (result > N) {
		std::cout << result - c.get_den() << "\n";
		break;
	    }
	}
    }
    return 0;
}
