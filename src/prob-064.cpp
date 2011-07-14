#include <iostream>
#include <unordered_map>
#include <boost/lexical_cast.hpp>

const int N = 10000;

int main() {
    int numberOfOddPeriods = 0;
    for (int n = 1; n <= N; ++n) {
	int a0 = 0, r = 0, d = 1;
	while (n - (r - 1) * (r - 1) >= 0) --r, ++a0;
	d = n - r * r;
	r = -r;

	std::unordered_map<int, int> pool;
	for (int i = 0; d != 0; ++i) {
	    int sig = d * n + r;

	    if (pool.find(sig) != pool.end()) {
		if ((i - pool[sig]) % 2) ++numberOfOddPeriods;
		break;
	    }

	    pool[sig] = i;

	    int a = 0;
	    while (n - (r - d) * (r - d) >= 0) ++a, r -= d;
	    d = (n - r * r) / d;
	    r = -r;
	}
    }

    std::cout << numberOfOddPeriods << "\n";
    return 0;
}
