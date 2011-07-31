#include <iostream>

const int N = 1000000;
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n])
	    for (int m = n + n; m <= N; m += n) composite[m] = true;

    int sum = 0;
    for (int n = 91, i = 1; i <= 25; n += 2) {
	if (n % 5 == 0) continue;
	if (!composite[n]) continue;

	int j = 1, m = 1;
	while ((m %= n) > 0) {
	    m *= 10;
	    ++m;
	    ++j;
	}

	if ((n - 1) % j == 0) {
	    sum += n;
	    ++i;
	}
    }

    std::cout << sum << "\n";
    return 0;
}
