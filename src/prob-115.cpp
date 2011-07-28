#include <iostream>
#include <gmpxx.h>

// Shameless copy from Problem 114
const int N = 1000;
mpz_class cache[N + 1];

mpz_class fit(int m, int n) {
    if (n < 3) return 1;
    if (n <= N && cache[n] > 0) return cache[n];

    mpz_class result = 1;
    for (int k = m; k <= n; ++k) {
	for (int offset = 0; offset < n - k; ++offset)
	    result += fit(m, n - k - 1 - offset);
	result += 1;
    }

    if (n <= N) cache[n] = result;
    return result;
}

int main() {
    for (int n = 1; ; ++n) {
	mpz_class result = fit(50, n);
	if (result > 1000000) {
	    std::cout << n << "\n";
	    break;
	}
    }

    return 0;
}
