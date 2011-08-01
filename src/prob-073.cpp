#include <iostream>

const int D = 12000;
bool composite[D + 1];

int gcd(int n, int m) { // asume n > m
    while (true) {
	if (m == 0) return n;
	if (m == 1 || !composite[n]) return 1;
	int temp = m;
	m = n % m;
	n = temp;
    }
}

// NOTE: Did I miss something here?
//
// Check out the awesome optimizaion on the website
int main() {
    for (int n = 2; n <= D / 2; ++n)
	if (!composite[n]) 
	    for (int m = n + n; m <= D; m += n) composite[m] = true;

    int numberOfFractions = 0;
    for (int d = 4; d <= D; ++d) {
	int nl = d / 3 + 1, nu = d / 2 + (d % 2);

	if (!composite[d]) numberOfFractions += nu - nl;
	else 
	    for (int n = nl; n < nu; ++n)
		if (!composite[n] || gcd(d, n) == 1) ++numberOfFractions;
    }

    std::cout << numberOfFractions << "\n";
    return 0;
}
