#include <iostream>
#include <gmpxx.h>

mpz_class testDivide(mpz_class& n) {
    mpz_class maxDivider = ::sqrt(n);
    for (mpz_class divider = 2; divider <= maxDivider; ++divider) {
	if ((n % divider) == 0) 
	    return n / divider;
    }

    return 0; // means failed
}

int main() {
    mpz_class num("600851475143");
    mpz_class ld;

    while ((ld = testDivide(num)) != 0) 
	num = ld;

    std::cout << num << "\n";
    return 0;
}
