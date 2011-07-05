#include <iostream>
#include <algorithm>

const int N = 10000000;
bool composite[N + 1];

bool isPrime(int n) {
    if (n % 2 == 0) return false;
    if (n <= N) return !composite[n];

    for (int d = 2; d <= N; ++d) {
	if (composite[d]) continue;
	if (n % d == 0) return false;
    }

    if (n >= 2 * N) {
	for (int d = N + 1; d <= n / 2; d += 2) // skip even numbers
	    if (n % d == 0) return false;
    }

    return true;
}

int main() {
    for (int n = 2; n <= N / 2; ++n)
	for (int m = n + n; m <= N; m += n) composite[m] = true;

    int greatestPandigitalPrime = 0;

    for (int n = 2; n <= 9; ++n) {
	int seq[10];
	for (int i = 0; i < n; ++i) seq[i] = i + 1;

	do {
	    int num = 0;
	    for (int i = 0; i < n; ++i) num = 10 * num + seq[i];

	    if (isPrime(num)) greatestPandigitalPrime = num;
	} while (std::next_permutation(seq, seq + n));
    }

    std::cout << greatestPandigitalPrime << "\n";
    return 0;
}
