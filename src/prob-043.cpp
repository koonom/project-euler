#include <iostream>
#include <algorithm>
#include <gmpxx.h>

int main() {
    int prime[7] = { 2, 3, 5, 7, 11, 13, 17 };
    int d[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    mpz_class sum = 0;

    do {
	bool good = true;
	for (int i = 0; i < 7; ++i) {
	    int n = 100 * d[i + 1] + 10 * d[i + 2] + d[i + 3];
	    if (n % prime[i]) {
		good = false;
		break;
	    }
	}

	if (good) {
	    mpz_class n = 0;
	    for (int i = 0; i < 10; ++i) n = 10 * n + d[i]; 
	    sum += n;
	}

    } while (std::next_permutation(d, d + 10));

    std::cout << sum << "\n";
    return 0;
}
