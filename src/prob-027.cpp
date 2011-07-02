#include <iostream>
#include <cassert>

const int N = 1000000;
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N/2; ++n) {
	if (composite[n]) continue;
	for (int m = 2 * n; m <= N; m += n) 
	    composite[m] = true;
    }

    int bestProduct = 0, longestChain = 0;
    composite[0] = composite[1] = true;

    for (int a = -999; a < 1000; ++a) {
	for (int b = -999; b < 1000; ++b) {
	    int n = 0, val;

	    while ((val = (n + a) * n + b) > 0)
		if (composite[val]) break;
		else ++n;

	    assert(val <= N);

	    if (longestChain < n) {
		longestChain = n;
		bestProduct = a * b;
	    }
	}
    }

    std::cout << bestProduct << "\n";
    return 0;
}
