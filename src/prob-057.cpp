#include <iostream>
#include <gmpxx.h>

int main() {
    int count = 0;
    mpq_class n(0);
    for (int i = 1; i <= 1000; ++i) { 
	n += 2; // plus 2 and invert
	mpq_inv(n.get_mpq_t(), n.get_mpq_t());

	mpz_class num = n.get_num(), denom = n.get_den();
	num += denom;

	if (num.get_str().size() > denom.get_str().size()) ++count;
    }

    std::cout << count << "\n";
    return 0;
}
