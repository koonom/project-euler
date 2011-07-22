#include <iostream>
#include <gmpxx.h>

// NOTE: Runs in 1 minutes.  Not satisfactory.
int main() {
    const int N = 1000000000;

    mpz_class sumOfPerimeters = 0, p = 0;
    for (int n = 3; 3 * n + 1 <= N; n += 2) { // HACK
	p = 3 * n - 1;
	p *= n + 1;
	if (mpz_perfect_square_p(p.get_mpz_t())) sumOfPerimeters += 3 * n - 1;

	p = 3 * n + 1;
	p *= n - 1;
	if (mpz_perfect_square_p(p.get_mpz_t())) sumOfPerimeters += 3 * n + 1;
    }

    std::cout << sumOfPerimeters << "\n";
    return 0;
}
