#include <iostream>
#include <gmpxx.h>

// NOTE: Courtesy of http://oeis.org/A002407
int main() {
    int count = 0;
    for (mpz_class k = 1; ; ++k) {
	mpz_class n = 3 * k * (k + 1) + 1;
	if (n > 1000000) break;
	if (mpz_probab_prime_p(n.get_mpz_t(), 3)) ++count;
    }

    std::cout << count << "\n";
    return 0;
}
