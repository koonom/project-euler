#include <iostream>
#include <gmpxx.h>

// Shameless copy from Problem 114
const int N = 50;
mpz_class cache[N + 1][5]; // don't care much about the extra 2/5 space

mpz_class fit(int n, int k) {
    if (k < 2 || k > 4) return 0;
    if (n < k) return 0;
    if (n <= N && cache[n][k] > 0) return cache[n][k];

    mpz_class result = 0;
    for (int offset = 0; offset < n - k; ++offset)
	result += fit(n - k - offset, k) + 1;
    result += 1;

    if (n <= N) cache[n][k] = result;
    return result;
}

int main() {
    std::cout << fit(N, 2) + fit(N, 3) + fit(N, 4) << "\n";
    return 0;
}
