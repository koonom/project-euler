#include <iostream>
#include <gmpxx.h>

#include "ContinuedFraction.hpp"

const int L = 100000000;

int main() {
    ContinuedFraction fraction = ContinuedFraction::squareRoot(2);

    mpq_class beforeLast, last, current;
    mpz_class total = 0;

    for (int n = 0; ; ++n) {
	beforeLast = last;
	last = current;
	current = (n == 0 || n == 1)?  fraction.getConvergent(n): 
	    fraction.getNextConvergent(n, beforeLast, last);

	mpz_class s2 = current.get_num() * current.get_num();
	mpz_class n2 = current.get_den() * current.get_den();

	if (s2 - 2 * n2 == -1) {
	    mpz_class maxK = L;
	    maxK /= (current.get_num() + current.get_den());

	    if (maxK <= 1) break;
	    if (current.get_num() == 1) continue;

	    mpz_class sum = maxK - 1; 
	    if (current.get_num() % 2 == 0) sum /= 2;

	    std::cout << n << ' ' << current << ' ' << sum << std::endl;
	    total += sum;

	}
    }

    std::cout << total << "\n";

    return 0;
}
