#include <cmath>
#include <iostream>

const int T = 1000000;

int main() {
    int m = 0;

    int numberOfSolutions = 0;
    while (++m) {
	for (int ij = 2; ij <= 2 * m; ++ij) {
	    int a1 = ij * ij + m * m;
	    int s1 = std::sqrt(a1);
	    if (s1 * s1 == a1) 
		numberOfSolutions += ((ij > m + 1)? ij / 2 - (ij - m - 1): ij / 2);
	}

	if (numberOfSolutions > T) break;
    }

    std::cout << m << "\n";
    return 0;
}
