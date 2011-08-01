#include <algorithm>
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

//--------------------------------------------------
// Shameless copy from the Problem 69
//-------------------------------------------------- 
const int N = 10000000;
int composite[N + 1]; // modified for storing the minimum prime factor

int totient(int n) {
    if (n < 1 || n > N) return -1;
    if (n == 1) return 1;
    if (!composite[n]) return n - 1;

    int d = composite[n];
    int m = n / d, k = 1;
    while (m % d == 0) m /= d, ++k;

    int p_k = 1;
    for (int i = 0; i < k; ++i) p_k *= d; 

    if (m > 1) return totient(m) * p_k / d * (d - 1); // \phi(mn) = \phi(m) \phi(n) 
    else return p_k / d * (d - 1); // \phi(p^k) = p^k (1 - 1 / p)
}

// NOTE: Wanna do more optimization
//
// This is one of the classic problem that I like.  Check out more optimization
// idea on the Project Euler forum.
int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n]) 
	    for (int m = n + n; m <= N; m += n) composite[m] = n;

    double minRatio = N;
    int bestN = 1;
    for (int n = 2; n < N; ++n) {
	int t = totient(n);

	double ratio = double(n) / t;
	if (ratio >= minRatio) continue;

	int digits[10];
	for (int i = 0; i < 10; ++i) digits[i] = 0;
	for (int m = n; m; m /= 10) ++digits[m % 10];
	for (int m = t; m; m /= 10) --digits[m % 10];

	bool good = true;
	for (int i = 0; i < 10; ++i) 
	    if (digits[i]) good = false;

	if (!good) continue;

	minRatio = ratio;
	bestN = n;
    }

    std::cout << bestN << "\n";
    return 0;
}
