#include <iostream>
#include <gmpxx.h>

const int N = 1100000;
bool composite[N + 1];

//--------------------------------------------------
// This solution is courtesy of Linear Congruence Theorem
//
// Based on http://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
//-------------------------------------------------- 
int gcd(int a, int b, int& r, int& s) {
    int x = 0, lastX = 1;
    int y = 1, lastY = 0;

    while (b != 0) {
	int q = a / b;
	a %= b; std::swap(a, b);
	lastX -= q * x; std::swap(x, lastX);
	lastY -= q * y; std::swap(y, lastY);
    }

    r = lastX;
    s = lastY;
    return a;
}

int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n])
	    for (int m = n + n; m <= N; m += n) composite[m] = true;

    mpz_class sum = 0;
    int last = 5, prod = 10;
    for (int n = 7; last <= 1000000; n += 2) {
	if (composite[n]) continue;
	while (prod < last) prod *= 10;

	int diff = n - last;

	int r, s;
	gcd(prod, n, r, s);
	int ll = r * diff;
	while (ll < 0) ll += n;
	while (ll >= n) ll -= n;

	mpz_class sol = prod;
	sol *= ll;
	sol += last;
	sum += sol;

	last = n;
    }

    std::cout << sum << "\n";
    return 0;
}
