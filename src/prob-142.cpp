#include <cmath>
#include <iostream>
#include <limits>
#include <gmpxx.h>

const int N = std::sqrt(std::numeric_limits<int>::max());

bool isSquare(int n) {
    int s = std::sqrt(n);
    return s * s == n;
}

// NOTE: Should have tried brute-force in the first place
int main() {
    for (int a = 1; a <= N; ++a) {
	int a2 = a * a;
	for (int b = 1; b < a; ++b) {
	    int b2 = b * b;

	    if (!isSquare(a2 - b2)) continue;
	    for (int c = 1; c < b; ++c) {
		int c2 = c * c;

		if (!isSquare(a2 - c2)) continue;
		if (!isSquare(b2 - c2)) continue;

		mpz_class x = a2;
		x += b2 - c2;
		if (x % 2 != 0) continue;
		x /= 2;

		mpz_class y = c2;
		y += a2 - b2;
		if (y % 2 != 0) continue;
		y /= 2;

		mpz_class z = b2;
		z -= a2 - c2;
		if (z % 2 != 0) continue;
		z /= 2;

		if (z < 0) continue;
		if (x < y) continue;
		if (y < z) continue;

		std::cout << x + y + z << std::endl;
		return 0;
	    }
	}
    }
}
