#include <iostream>

const int N = 1000000;
int nsols[N + 1];

// NOTE: The key is in the equation: m(4r - m) = n
int main() {
    for (int m = 1; m <= N; ++m) {
	int k_ub = 3 * m;
	for (int k = 1, km = m; k < k_ub && km <= N; ++k, km += m) {
	    if ((k + m) % 4) continue;
	    int r = (k + m) / 4;
	    ++nsols[km];
	}
    }

    int nmatches = 0;
    for (int m = 1; m <= N; ++m)
	if (nsols[m] == 10) ++nmatches;

    std::cout << nmatches << "\n";
    return 0;
}
