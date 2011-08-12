#include <iostream>
#include <gmpxx.h>

const int N = 150000000;

// NOTE: Grrr.  I brute-force all the way out (~3 min).  How do I optimize?
int main() {
    mpz_class sum = 0;
    for (int n = 10; n <= N; n += 10) {
	mpz_class n2, p;
	mpz_ui_pow_ui(n2.get_mpz_t(), n, 2);
	
	n2 += 1;
	if (!mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (!mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (!mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (!mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (!mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;
	n2 += 2;
	if (!mpz_probab_prime_p(n2.get_mpz_t(), 3)) continue;

	sum += n;
	std::cout << n << std::endl;
    }

    std::cout << sum << "\n";
}
