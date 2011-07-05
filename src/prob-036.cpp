#include <iostream>

int main() {
    int sum = 0;
    for (int i = 1; i < 1000000; ++i) {
	if ((i & 1) == 0) continue;

	int digits[6];
	int ndigits = 0;

	for (int n = i; n > 0; n /= 10) digits[ndigits++] = n % 10;

	int j = 0, k = ndigits - 1;
	while (j < k && digits[j] == digits[k]) ++j, --k;
	if (j < k) continue;

	int nbits = 0;
	for (int n = i; n > 0; n >>= 1) ++nbits;

	int jj = 0, kk = nbits - 1;
	while (jj < kk && (((i >> jj) & 1) ^ ((i >> kk) & 1)) == 0) ++jj, --kk;
	if (jj < kk) continue;

	sum += i;
    }

    std::cout << sum << "\n";
    return 0;
}
