#include <iostream>

const int N = 1000000 - 1;
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	for (int m = n + n; m <= N; m += n)
	    composite[m] = true;

    composite[0] = composite[1] = true;

    int sum = 0;
    for (int n = 10; n <= N; ++n) {
	if (composite[n]) continue;

	int digits[6];
	int ndigits = 0;
	for (int i = n; i > 0; i /= 10) digits[ndigits++] = i % 10;

	bool good = true;
	int leftRunning = 0, rightRunning = 0, factor = 1;
	for (int j = 0, factor = 1; j < ndigits - 1; ++j, factor *= 10) {
	    leftRunning = 10 * leftRunning + digits[ndigits - 1 - j];
	    rightRunning += factor * digits[j];

	    if (composite[leftRunning] || composite[rightRunning]) {
		good = false;
		break;
	    }
	}

	if (good) sum += n;
    }

    std::cout << sum << "\n";
    return 0;
}
