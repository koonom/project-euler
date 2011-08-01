#include <iostream>

// Shameless copy from Problems 129 and 130
const int N = 1000000, M = 1000000000;
bool composite[N + 1];

// NOTE: Runs in 30 seconds.  Merely okay.
int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n])
	    for (int m = n + n; m <= N; m += n) composite[m] = true;

    int sum = 0;
    for (int n = 3, i = 1; i <= 40 && n <= N; n += 2) {
	if (n % 5 == 0) continue;
	if (composite[n]) continue;

	int j = 1, m = 1;
	while (j <= M && (m %= n) > 0) {
	    m *= 10;
	    ++m;
	    ++j;
	}

	if (j > M) continue;
	if (M % j) continue;

	sum += n;
	++i;
    }

    std::cout << sum << "\n";
    return 0;
}
