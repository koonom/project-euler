#include <iostream>
#include <cmath>

int main() {
    int powers[10];
    for (int p = 0; p < 10; ++p) powers[p] = pow(p, 5);

    const int ndigits = 8;
    const int N = ndigits * pow(9, 5);
    int sumOfPowers = 0;

    for (int n = 10; n < N ; ++n) {
	int q = n;
	int sum = 0;
	for (int d = 0; d < ndigits; ++d) {
	    sum += powers[q % 10];
	    q /= 10;
	}

	if (sum == n) sumOfPowers += n;
    }

    std::cout << sumOfPowers << "\n";
    return 0;
}
