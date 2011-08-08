#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <gmpxx.h>

#include "ContinuedFraction.hpp"

// NOTE: Using Pell equation to solve x^2 - 5 y^2 = 44
int main() {
    int p[3], q[3], nsols = 0;

    for (int x = 1; nsols < 3; ++x) {
	for (int y = 1; ; ++y) {
	    int r = x * x - 5 * y * y;
	    if (r > 44) continue;

	    if (r == 44) {
		p[nsols] = x;
		q[nsols] = y;
		++nsols;
	    }

	    break;
	}
    }

    std::vector<mpz_class> nuggets;
    ConvergentGenerator gen(5);
    
    while (nuggets.size() < 100) {
	const mpq_class& c = gen.nextConvergent();
	mpz_class r = c.get_num(), s = c.get_den();
    
	for (int i = 0; i < 3; ++i) {
	    mpz_class x = p[i] * r + 5 * q[i] * s;
	    mpz_class y = p[i] * s + q[i] * r;

	    if (x * x - 5 * y * y == 44 && x % 5 == 2)
		nuggets.push_back((x - 7) / 5);

	    x = p[i] * r - 5 * q[i] * s;
	    y = p[i] * s - q[i] * r;
	    if (x * x - 5 * y * y == 44) {
		if (x < 0) x = -x;
		if (y < 0) y = -y;

		if (x % 5 == 2) nuggets.push_back((x - 7) / 5);
	    }
	}
    }

    std::partial_sort(nuggets.begin(), nuggets.begin() + 30, nuggets.end());
    mpz_class sum = 0;
    for (int i = 0; i < 30; ++i) sum += nuggets[i];

    std::cout << sum << "\n";
    return 0;
}
