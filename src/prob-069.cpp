#include <iostream>
#include <vector>

const int N = 1000000;
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

    if (m > 1) return totient(m) * totient(p_k); // \phi(mn) = \phi(m) \phi(n) 
    else return p_k / d * (d - 1); // \phi(p^k) = p^k (1 - 1 / p)
}

int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n]) 
	    for (int m = n + n; m <= N; m += n) composite[m] = n;

    double maxRatio = 1;
    int bestN = 1;
    for (int n = 2; n <= N; ++n) {
	double ratio = double(n) / totient(n);
	if (ratio > maxRatio) {
	    maxRatio = ratio;
	    bestN = n;
	}
    }

    std::cout << bestN << "\n";
    return 0;
}
