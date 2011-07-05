#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class base, sum(0);
    mpz_ui_pow_ui(base.get_mpz_t(), 10, 10);

    for (int i = 1; i <= 1000; ++i) {
	mpz_class m;
	mpz_ui_pow_ui(m.get_mpz_t(), i, i);
	m %= base;
	sum += m;
    }

    sum %= base;
    std::cout << sum << "\n";
    return 0;
}
