#include <iostream>
#include <gmpxx.h>

// Courtesy of http://oeis.org/A007805
int main() {
    mpz_class sum = 0;
    for (int n = 1; n <= 12; ++n) {
	mpz_class l;
	mpz_fib_ui(l.get_mpz_t(), 6 * n + 3);
	sum += l / 2;
    }

    std::cout << sum << "\n";
    return 0;
}
