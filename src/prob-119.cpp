#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <gmpxx.h>

const int N = 20;

int main() {
    mpz_class limit;
    mpz_ui_pow_ui(limit.get_mpz_t(), 10, N);

    std::vector<mpz_class> numbers;

    int maxN = 9 * N;
    for (int i = 2; i <= maxN; ++i) {
	for (mpz_class n = i; n <= limit; n *= i) {
	    if (n < 10) continue;

	    int d = 0;
	    std::string rep = n.get_str();
	    for (int j = 0; j < rep.size(); ++j) d += rep[j] - '0';

	    if (d == i) numbers.push_back(n);
	}
    }

    std::sort(numbers.begin(), numbers.end());
    if (numbers.size() >= 30)
	std::cout << numbers[29] << "\n";

    return 0;
}
