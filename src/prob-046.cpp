#include <iostream>

const int N = 1000000;
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	for (int m = n + n; m <= N; m += n) composite[m] = true;

    for (int n = 3; n <= N; n += 2) {
	if (!composite[n]) continue;

	bool good = false;
	for (int i = 1, s = 1; 2 * s < n; ++i, s = i * i) {
	    if (!composite[n - 2 * s]) {
		good = true;
		break;
	    }
	}

	if (!good) {
	    std::cout << n << "\n";
	    return 0;
	}
    }

    return 0;
}
