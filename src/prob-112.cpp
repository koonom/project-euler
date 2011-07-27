#include <iostream>
#include <limits>

int main() {
    int maxInteger = std::numeric_limits<int>::max();
    int digits[10];

    int bouncyCount = 0;
    for (int n = 1; n <= maxInteger; ++n) {
	int ndigits = 0;
	for (int m = n; m; m /= 10) digits[ndigits++] = m % 10;

	int i = 1;
	while (i < ndigits && digits[i] >= digits[i - 1]) ++i;
	if (i == ndigits) continue;

	i = 1;
	while (i < ndigits && digits[i] <= digits[i - 1]) ++i;
	if (i == ndigits) continue;

	++bouncyCount;
	if ((double) bouncyCount * 100 == n * 99) {
	    std::cout << n << "\n";
	    break;
	}
    }

    return 0;
}
