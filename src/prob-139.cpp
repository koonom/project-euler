#include <iostream>
#include <gmpxx.h>

#include "ContinuedFraction.hpp"

const int L = 100000000;

// NOTE: Analysis goes first.
int main() {
    ContinuedFraction fraction = ContinuedFraction::squareRoot(2);

    mpq_class beforeLast, last, current;
    mpz_class total = 0;

    for (int i = 0; ; ++i) {
	beforeLast = last;
	last = current;
	current = (i == 0 || i == 1)?  fraction.getConvergent(i): 
	    fraction.getNextConvergent(i, beforeLast, last);

	if (current.get_den() >= L) break;

	mpz_class s2 = current.get_num() * current.get_num();
	mpz_class n2 = current.get_den() * current.get_den();

	if (s2 - 2 * n2 == -1) {
	    mpz_class s = current.get_num(), n = current.get_den();

	    mpz_class maxK = L - 1;
	    maxK /= s + n;

	    if (maxK <= 0 || s >= 2 * n - 1) continue;

	    mpz_class sum = maxK; 
	    if ((s - 1) % 2 == 1) sum /= 2;

	    total += sum;
	}
    }

    std::cout << total << "\n";
    return 0;
}
