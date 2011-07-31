#include <algorithm>
#include <iostream>
#include <gmpxx.h>

const int N = 15;

int main() {
    bool outcomes[N];
    mpz_class sum = 0;

    for (int l = N / 2 + 1; l <= N; ++l) {
	std::fill_n(outcomes, l, false); // blue discs
	std::fill_n(outcomes + l, N - l, true);

	do {
	    mpz_class p = 1;
	    for (int i = 0; i < N; ++i)
		if (outcomes[i]) p *= i + 1;
	    sum += p;
	} while (std::next_permutation(outcomes, outcomes + N));
    }

    mpz_class prod;
    mpz_fac_ui(prod.get_mpz_t(), N + 1);

    std::cout << prod / sum << "\n";
    return 0;
}
