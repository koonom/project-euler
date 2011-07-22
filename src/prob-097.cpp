#include <iostream>
#include <gmpxx.h>

const int N = 7830457;
const int C = 28433;

int main() {
    mpz_class z, n, base(2);
    mpz_ui_pow_ui(z.get_mpz_t(), 10, 10);
    mpz_powm_ui(n.get_mpz_t(), base.get_mpz_t(), N, z.get_mpz_t());
    n *= C;
    n += 1;
    n %= z;

    std::cout << n << "\n";
    return 0;
}
