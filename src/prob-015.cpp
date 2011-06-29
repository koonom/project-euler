#include <iostream>
#include <gmpxx.h>

int main() {
    const int N = 20;
    mpz_class numberOfWays[N + 1]; // Use GMP to prevent overflow

    for (int j = 0; j <= N; ++j) 
	numberOfWays[j] = 1;

    for (int k = 0; k < N; ++k) 
	for (int j = N - 1; j >= 0; --j)
	    numberOfWays[j] += numberOfWays[j + 1];

    std::cout << numberOfWays[0] << "\n";
    return 0;
}
