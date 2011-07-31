#include <algorithm>
#include <iostream>
#include <string>
#include <gmpxx.h>

int dissect(char* first, char* last, mpz_class m) {
    if (first == last) return 1;

    int sum = 0;
    for (char* l = first + 1; l <= last; ++l) {
	std::string s(first, l - first);
	mpz_class n(s);
	if (n <= m) continue;
	if (mpz_probab_prime_p(n.get_mpz_t(), 5))
	    sum += dissect(l, last, n);
    }

    return sum;
}

// NOTE: Runs in 9 seconds.  Not really satisfactory.
int main() {
    int sum = 0;
    char digits[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0' };

    do {
	sum += dissect(digits, digits + 9, 0);
    } while (std::next_permutation(digits, digits + 9));

    std::cout << sum << "\n";
    return 0;
}
