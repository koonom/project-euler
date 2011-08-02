#include <iostream>
#include <gmpxx.h>

bool prime(mpz_class n) {
    return mpz_probab_prime_p(n.get_mpz_t(), 3);
}

// NOTE: The key is to identify patterns for x where PD(x) == 3
int main() {
    int threeCount = 1;
    mpz_class base = 1, layer = 0, ntiles = 1;

    while (true) {
	mpz_class last_ntiles = ntiles;

	layer += 1;
	base += ntiles;
	ntiles = 6 * layer;

	// Case 1: Head corner (0, 0)
	if (prime(ntiles - 1) && prime(ntiles + 1) && prime(ntiles + (ntiles + 6) - 1)) 
	    ++threeCount;

	if (threeCount == 2000) {
	    std::cout << base << std::endl;
	    return 0;
	}

	// Case 2: Tail edge (5, layer - 1)
	if (prime(ntiles - 1) && prime(last_ntiles + ntiles - 1) && prime((ntiles + 6) - 1))
	    ++threeCount;

	if (threeCount == 2000) {
	    std::cout << base + ntiles - 1 << std::endl;
	    return 0;
	}
    }
}
