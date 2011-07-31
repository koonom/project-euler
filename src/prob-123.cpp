#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class p(2), limit;
    mpz_ui_pow_ui(limit.get_mpz_t(), 10, 10);

    for (int n = 1; ; n += 2) {
	if (2 * n * p > limit) {
	    std::cout << n << "\n";
	    break;
	}
	mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
	mpz_nextprime(p.get_mpz_t(), p.get_mpz_t());
    }
    return 0;
}
