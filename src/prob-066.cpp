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
	ContinuedFraction fraction = ContinuedFraction::squareRoot(d);
	if (fraction.getPeriod() == 0) continue;

	mpq_class beforeLast, last, current;

	for (int n = 0; ; ++n) {
	    beforeLast = last;
	    last = current;

	    current = (n == 0 || n == 1)? 
		fraction.getConvergent(n): fraction.getNextConvergent(n, beforeLast, last);

	    mpz_class x2;
	    mpz_pow_ui(x2.get_mpz_t(), current.get_num().get_mpz_t(), 2);

	    mpz_class y2;
	    mpz_pow_ui(y2.get_mpz_t(), current.get_den().get_mpz_t(), 2);

	    if (x2 - d * y2 == 1) {
		if (largestX < current.get_num()) {
		    largestX = current.get_num();
		    largestD = d;
		}
		break;
	    }
	}
    }

    std::cout << largestD << "\n";
    return 0;
}
