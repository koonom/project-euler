#include <iostream>

int gcd(int n, int m) { // assume n > m
    if (m == 1) return 1;
    if (m == 0) return n;
    return gcd(m, n % m);
}

int main() {
    int nn = 1, dd = 1;
    for (int a = 1; a <= 9; ++a) 
	for (int b = a + 1; b <= 9; ++b)
	    for (int c = 1; c <= 9; ++c) {
		if ((b * (10 * a + c) == a * (10 * c + b)) || 
		    (b * (10 * c + a) == a * (10 * b + c))) 
		{
		    nn *= a;
		    dd *= b;
		}
	    }

    std::cout << dd / gcd(dd, nn) << "\n";
    return 0;
}
