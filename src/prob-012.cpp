#include <cmath>
#include <iostream>

int factorize(int n) {
    if (n == 1) return 1;

    int numberOfFactors = 1;
    int maxFactor = n / 2;

    for (int i = 2; i <= maxFactor ; ++i) {
	if (n % i) continue;

	int rep = 0; // I don't care doing once more
	while (n % i == 0) {
	    ++rep;
	    n /= i;
	}

	numberOfFactors *= rep + 1;
	if (n == 1) break;
    }

    if (n > maxFactor) return 2;
    else return numberOfFactors;
}

int main() {
    int triangle = 0, summand = 1;
    int numberOfFactors;

    do {
	triangle += summand++;
	numberOfFactors = factorize(triangle);
    } while (numberOfFactors <= 500);

    std::cout << triangle << "\n";
    return 0;
}
