#include <iostream>
#include <gmpxx.h>

static int cache[1000001];

int getChainSize(mpz_class& n) {
    int cacheIndex = (n <= 1000000)? n.get_si(): 0;
    if (cache[cacheIndex]) return cache[cacheIndex];

    if (n % 2 == 0) n /= 2; 
    else n = 3 * n + 1;
    int subChainSize = getChainSize(n);

    if (cacheIndex) cache[cacheIndex] = 1 + subChainSize;
    return 1 + subChainSize;
}

int main() {
    int startingPoint = 1, largestChainSize = 1;

    cache[0] = 0;
    cache[1] = 1;

    for (int n = 2; n < 1000000; ++n) {
	mpz_class num(n);
	int chainSize = getChainSize(num);

	if (chainSize > largestChainSize) {
	    largestChainSize = chainSize;
	    startingPoint = n;
	}
    }

    std::cout << startingPoint << "\n";
    return 0;
}
