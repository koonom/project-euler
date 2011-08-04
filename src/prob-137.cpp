#include <iostream>
#include <gmpxx.h>

// NOTE: It's getting really easy once you figure out the recurrence
int main() {
    mpz_class n, d(1);
    for (int i = 1; i <= 15; ++i) {
	n += d;
	std::swap(n, d);
	n += d;
	std::swap(n, d);
    }

    mpq_class r(d * n, d * d - d * n - n * n);
    std::cout << r << "\n";
    return 0;
}
