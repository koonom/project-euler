#include <iostream>

int main() {
    int bestP = 0, bestNumberOfSolutions = 0;

    for (int p = 3; p <= 1000; ++p) {
	int nsolutions = 0;
	int p2 = p * p;

	for (int x = 1; x <= p; ++x) 
	    for (int y = x + 1; y <= p; ++y) {
		if (p - x - y < y) break;
		if (p2 == 2 * (p * (x + y) - x * y)) ++nsolutions;
	    }

	if (bestNumberOfSolutions < nsolutions) {
	    bestNumberOfSolutions = nsolutions;
	    bestP = p;
	}
    }

    std::cout << bestP << "\n";
    return 0;
}
