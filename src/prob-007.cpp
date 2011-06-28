#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class n = 2, temp;

    for (int i = 0; i < 10000; ++i) {
	::mpz_nextprime(temp.get_mpz_t(), n.get_mpz_t());
	n = temp;
    }

    std::cout << n << "\n";
    return 0;
}
