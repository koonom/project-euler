#include <iostream>
#include <gmpxx.h>

#include "ContinuedFraction.hpp"

// NOTE: I got stuck for two days while bruteforcing my way out.
//
// Courtesy of http://mukeshiiitm.wordpress.com/2011/02/11/project-euler-problem-100/
int main() {
    mpz_class N;
    mpz_ui_pow_ui(N.get_mpz_t(), 10, 12);

    ContinuedFraction fraction = ContinuedFraction::squareRoot(8);
    mpq_class beforeLast, last, current = fraction.getConvergent(0);

    for (int n = 1; ; ++n) {
	beforeLast = last;
	last = current;
	current = (n == 1)? fraction.getConvergent(1): 
	    fraction.getNextConvergent(n, beforeLast, last);

	mpz_class x2, r2;
	mpz_pow_ui(x2.get_mpz_t(), current.get_num().get_mpz_t(), 2);
	mpz_pow_ui(r2.get_mpz_t(), current.get_den().get_mpz_t(), 2);

	if (x2 - 8 * r2 == 1) {
	    mpz_class result = 2 * current.get_den() + (current.get_num() + 1) / 2;
	    if (result > N) {
		std::cout << result - current.get_den() << "\n";
		break;
	    }
	}
    }
    return 0;
}
