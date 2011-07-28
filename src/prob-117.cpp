#include <iostream>
#include <gmpxx.h>

// Shameless copy from Problem 114
const int N = 50;
mpz_class cache[N + 1];

mpz_class fit(int n) {
    if (n < 2) return 1;
    if (n <= N && cache[n] > 0) return cache[n];

    mpz_class result = 1;
    for (int k = 2; k <= 4; ++k) {
	if (n < k) break;

	result += 1;
	for (int offset = 0; offset < n - k; ++offset)
	    result += fit(n - k - offset);
    }

    if (n <= N) cache[n] = result;
    return result;
}

int main() {
    std::cout << fit(N) << "\n";
    return 0;
}
