#include <algorithm>
#include <iostream>
#include <vector>

#include <gmpxx.h>

const int N = 1000000;
const int sqrtN = 1000;
std::vector<int> factors[N + 1];

// NOTE: Run about 72 seconds.
int main() {
    for (int n = 2; n <= N / 2; ++n)
	for (int m = n + n; m <= N; m += n) factors[m].push_back(n);

    mpz_class n, n2, d3, N2;
    mpz_ui_pow_ui(N2.get_mpz_t(), N, 2);

    std::vector<mpz_class> resultingSquares;

    for (int d = 2; d <= N; ++d) {
	if (factors[d].empty()) {
	    mpz_ui_pow_ui(n2.get_mpz_t(), d, 3);
	    n2 += 1;
    
	    if (!mpz_perfect_square_p(n2.get_mpz_t())) continue;
	    resultingSquares.push_back(n2);
	}
	else {
	    mpz_ui_pow_ui(d3.get_mpz_t(), d, 3);

	    std::vector<int>& f = factors[d];
	    std::vector<int> f2;

	    for (int i = 0; i < f.size(); ++i) {
		int rr = f[i];
		int ub = d / rr;

		f2.push_back(rr);
		for (int j = 0; j <= i && f[j] < ub; ++j)
		    f2.push_back(rr * f[j]);
	    }

	    for (int i = 0; i < f2.size(); ++i) {
		int r = f2[i];
		n2 = d3 / r + r;

		if (n2 >= N2) continue;
		if (!mpz_perfect_square_p(n2.get_mpz_t())) continue;
		resultingSquares.push_back(n2);
	    }
	}
    }

    std::sort(resultingSquares.begin(), resultingSquares.end());
    resultingSquares.erase(
	std::unique(resultingSquares.begin(), resultingSquares.end()),
	resultingSquares.end());

    mpz_class sumOfSquares = 0;
    for (int i = 0; i < resultingSquares.size(); ++i)
	sumOfSquares += resultingSquares[i];

    std::cout << sumOfSquares << "\n";
    return 0;
}

