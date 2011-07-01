#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class f_n = 2, f_nsub1 = 1, f_nsub2 = 1;
    int n = 3;

    while (f_n.get_str().length() < 1000) {
	f_nsub2 = f_nsub1;
	f_nsub1 = f_n;
	f_n = f_nsub1 + f_nsub2;
	++n;
    }

    std::cout << n << "\n";
    return 0;
}
