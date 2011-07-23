#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class m, numberOfBlueDiscs;
    mpz_ui_pow_ui(m.get_mpz_t(), 10, 12);

    while (true) {
	bool found = false;
	mpz_class ub = m * 71 / 100, dest = m * (m - 1);
	std::cout << m << std::endl;
	for (mpz_class n = m * 7 / 10; n <= ub; ++n) {
	    std::cout << n << ' ' << ub << std::endl;
	    if (2 * n * (n - 1) == dest) {
		numberOfBlueDiscs = n;
		found = true;
		break;
	    }
	}

	if (found) break;
	++m;
    }

    std::cout << numberOfBlueDiscs << "\n";
    return 0;
}
