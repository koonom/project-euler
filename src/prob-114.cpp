#include <iostream>
#include <gmpxx.h>

const int N = 50;
mpz_class cache[N + 1];

mpz_class fit(int n) {
    if (n < 3) return 1;
    if (n <= N && cache[n] > 0) return cache[n];

    mpz_class result = 1;
    for (int k = 3; k <= n; ++k) {
	for (int offset = 0; offset < n - k; ++offset)
	    result += fit(n - k - 1 - offset);
	result += 1;
    }

    if (n <= N) cache[n] = result;
    return result;
}

int main() {
    std::cout << fit(N) << "\n";
    return 0;
}
