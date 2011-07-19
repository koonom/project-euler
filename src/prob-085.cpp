#include <cmath>
#include <iostream>

const int T = 2000000;

int main() {
    int minDiff = T, area = 0;
    for (int m = 1; m <= T; ++m) {
	double rhs = 4 * T / m / (m + 1);

	int n = std::sqrt(rhs);
	if (n < m) break;
	    
	while (true) { 
	    if (n * (n + 1) > rhs) break;

	    int diff = 4 * T - m * (m + 1) * n * (n + 1);
	    if (diff < 0) diff = -diff;
	    if (diff < minDiff) {
		minDiff = diff;
		area = m * n;
	    }
	    ++n;
	} 
    }

    std::cout << area << "\n";
    return 0;
}
