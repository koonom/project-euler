#include <cmath>
#include <iostream>

#include "PythagoreanTriple.hpp"

const int T = 2000;

int main() {
    int m = 100, numberOfSolutions = 0;

    for (int i = 1; i <= m; ++i)
	for (int j = i; j <= m; ++j)
	    for (int k = j; k <= m; ++k) {
		int a1 = (i + j) * (i + j) + k * k;
		int a2 = (i + k) * (i + k) + j * j;
		int a3 = (j + k) * (j + k) + i * i;

		int m = std::min(a1, a2);
		m = std::min(a3, m);

		int s1 = std::sqrt(a1);
		int s2 = std::sqrt(a2);
		int s3 = std::sqrt(a3);

		bool good = false;
		if (m == a1 && s1 * s1 == a1) ++good;
		if (m == a2 && s2 * s2 == a2) ++good;
		if (m == a3 && s3 * s3 == a3) ++good;

		if (good) ++numberOfSolutions;
	    }

    std::cout << numberOfSolutions << "\n";
    return 0;
}
