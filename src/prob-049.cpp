#include <iostream>
#include <algorithm>

const int N = 100000;
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	for (int m = n + n; m <= N; m += n) composite[m] = true;

    for (int n = 1000; n <= 9999; ++n) {
	if (composite[n]) continue;

	int digits[4]; // in the regular order
	for (int m = n, i = 4; m > 0; m /= 10) digits[--i] = m % 10;

	int found = 0;
	while (std::next_permutation(digits, digits + 4)) {
	    int nn = 0;
	    for (int i = 0; i < 4; ++i) nn = 10 * nn + digits[i];

	    if (nn == n + 3330 && !composite[nn]) ++found;
	    if (nn == n + 6660 && !composite[nn]) ++found;

	    if (found == 2) break;
	}

	if (found == 2 && n != 1487) {
	    std::cout << n << n + 3330 << n + 6660 << "\n";
	    return 0;
	}
    }

    return 0;
}
