#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <gmpxx.h>

const int LIMIT = 100000000, N = 10000;
int square[N]; 
int sumOfSquares[N];

// NOTE: Always a catch.
int main() {
    for (int n = 0; n < N; ++n) 
	sumOfSquares[n] = square[n] = n * n;

    std::vector<int> numbers;
    int digits[9], ndigits;
    int offset = 1, ub = N;

    while (ub > 1) {
	for (int k = 1; k < ub; ++k) {
	    if (k + offset >= N) break;
	    sumOfSquares[k] += square[k + offset];
	    if (sumOfSquares[k] >= LIMIT) {
		ub = k;
		break;
	    }

	    ndigits = 0;
	    for (int m = sumOfSquares[k]; m > 0; m /= 10) digits[ndigits++] = m % 10;
	    int i = 0, j = ndigits - 1;
	    while (i < j && digits[i] == digits[j]) ++i, --j;
	    if (i < j) continue;
	    numbers.push_back(sumOfSquares[k]);
	}
	++offset;
    }

    mpz_class sum = 0;
    std::sort(numbers.begin(), numbers.end());
    std::vector<int>::iterator newEnd = std::unique(numbers.begin(), numbers.end());
    for (std::vector<int>::iterator i = numbers.begin(); i != newEnd; ++i) sum += *i;

    std::cout << sum << "\n";
    return 0;
}
