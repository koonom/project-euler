#include <iostream>

// Shameless copy from Problem 132
const int N = 100000;
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n])
	    for (int m = n + n; m <= N; m += n) composite[m] = true;

    int sum = 2 + 5; // always a catch
    for (int n = 3; n < N; n += 2) {
	if (n % 5 == 0) continue;
	if (composite[n]) continue;

	int j = 1, m = 1;
	while ((m %= n) > 0) {
	    m *= 10;
	    ++m;
	    ++j;
	}

	while (j % 2 == 0) j /= 2;
	while (j % 5 == 0) j /= 5;
	if (j != 1) sum += n;
    }

    std::cout << sum << "\n";
    return 0;
}
