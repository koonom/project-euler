#include <iostream>
#include <queue>
#include <gmpxx.h>

#include "PythagoreanTriple.hpp"

// Shameless copy from Problem 075
const int N = 400000, LIMIT = 1000;
int numberOfSolutions[N + 1];

int main() {
    typedef PythagoreanTriple<mpz_class> Triple;

    std::priority_queue<Triple, std::vector<Triple>, std::greater<Triple>> pool;
    pool.push(Triple::root());

    int lastChecked = 0; // the greatest verified N so far

    while (!pool.empty()) {
	Triple top = pool.top();
	pool.pop();

	int a = top.a.get_ui();
	for (int m = a; m <= 2 * N; m += a)
	    if ((m & 1) == 0) ++numberOfSolutions[m >> 1];

	if (top.b <= 2 * N) {
	    int b = top.b.get_ui();
	    for (int m = b; m <= 2 * N; m += b)
		if ((m & 1) == 0) ++numberOfSolutions[m >> 1];
	}

	for (int i = lastChecked + 1; i < a / 2; ++i)
	    if (numberOfSolutions[i] >= LIMIT) {
		std::cout << i << "\n";
		return 0;
	    }

	lastChecked = a / 2 - 1;

	for (int j = 1; j <= 3; ++j) {
	    Triple child = top.child(j);
	    if (child.a > 2 * N) break;
	    pool.push(top.child(j));
	}
    }

    return 0;
}
