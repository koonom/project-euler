#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class sum = 0;
    for (int a = 3; a <= 1000; ++a) {
	int a2 = a * a;
	int first = 2 * a % a2;
	int best = std::max(first, 2);

	for (int n = 3; ; n += 2) {
	    int v = 2 * n * a % a2;
	    if (v == first) break;
	    if (v > best) best = v;
	}
	sum += best;
    }

    std::cout << sum << "\n";
    return 0;
}
