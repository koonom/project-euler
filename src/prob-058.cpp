#include <iostream>
#include <gmpxx.h>

const int N = 1000000;
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n])
	    for (int m = n + n; m <= N; m += n) composite[m] = true;

    mpz_class n = 1; 
    int l = 1, numberOfPrimes = 0, numberOfTests = 1;
    while (l += 2) {
	for (int j = 0; j < 4; ++j) {
	    n += l - 1;
	    ++numberOfTests;

	    if (n <= N) {
		if (!composite[n.get_ui()]) ++numberOfPrimes;
	    }
	    else {
		if (mpz_probab_prime_p(n.get_mpz_t(), 5)) ++numberOfPrimes; 
	    }
	}

	double ratio = double(numberOfPrimes) / numberOfTests;
	if (ratio < 0.1) break;
    }

    std::cout << l << "\n";
    return 0;
}
