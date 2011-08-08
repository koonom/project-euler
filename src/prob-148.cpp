#include <iostream>
#include <gmpxx.h>

const int N = 1000000000;
const int NDIGITS = 11; // ceil(9 * log(10) / log(7));

mpz_class powers[NDIGITS];
mpz_class multipliers[8] = { 0, 1, 3, 6, 10, 15, 21, 28 };

mpz_class oracle(int n) {
    int digits[NDIGITS], ndigits = 0;
    for (int m = n; m; m /= 7) digits[ndigits++] = m % 7;

    mpz_class sum = 0, m = 1;
    for (int i = ndigits - 1; i >= 0; --i) {
	sum += m * multipliers[digits[i]] * powers[i];
	m *= digits[i] + 1;
    }

    return sum;
}

int main() {
    for (int i = 0; i < NDIGITS; ++i) 
	mpz_ui_pow_ui(powers[i].get_mpz_t(), 28, i);

    std::cout << oracle(N) << std::endl;
    return 0;
}

