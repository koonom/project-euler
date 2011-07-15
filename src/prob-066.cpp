#include <iostream>
#include <iterator>
#include <string>
#include <gmpxx.h>

#include "ContinuedFraction.hpp"

const int D = 1000;

int main() {
    mpz_class largestX = 0;
    int largestD = 0;

    // Find ``Pell's equation'' on Wikipedia for more info
    for (int d = 1; d <= D; ++d) {
	ContinuedFraction fraction(d);
	if (fraction.getPeriod() == 0) continue;

	for (int n = 1; ; ++n) {
	    mpq_class c = fraction.getConvergent(n);

	    mpz_class x2;
	    mpz_pow_ui(x2.get_mpz_t(), c.get_num().get_mpz_t(), 2);

	    mpz_class y2;
	    mpz_pow_ui(y2.get_mpz_t(), c.get_den().get_mpz_t(), 2);

	    if (x2 - d * y2 == 1) {
		if (largestX < c.get_num()) {
		    largestX = c.get_num();
		    largestD = d;
		}
		break;
	    }
	}
    }

    std::cout << largestD << "\n";
    return 0;
}
