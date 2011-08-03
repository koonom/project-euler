#include <iostream>

const int N = 1000000;
int nsols[N + 1];

// NOTE: The key is in the equation: m(4r - m) = n
int main() {
    for (int m = 2; m <= N; ++m) { // skip the case m = 1
	int k_lb = 4 - (m & 0x3); 
	int k_ub = 3 * m;
	for (int k = k_lb, km = k_lb * m; k < k_ub && km <= N; k += 4, km += (m << 2))
	    ++nsols[km];
    }

    int nmatches = 0;
    for (int m = 1; m <= N; ++m)
	if (nsols[m] == 10) ++nmatches;

    std::cout << nmatches << "\n";
    return 0;
}
