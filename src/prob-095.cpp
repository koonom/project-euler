#include <iostream>
#include <unordered_set>
#include <boost/lexical_cast.hpp>

const int N = 1000000;
int amicableNumber[N + 1];

int main() {
    for (int n = 1; n <= N / 2; ++n)
	for (int m = n + n; m <= N; m += n) amicableNumber[m] += n;

    int bestNumber = 0, longestChain = 0;
    std::unordered_set<int> chain;
    for (int n = 1; n <= N; ++n) {
	int current = n, smallest = n;
	chain.clear();

	do {
	    chain.insert(current);
	    if (current < smallest) smallest = current;
	    current = amicableNumber[current];
	} while (current > 0 && current <= N && chain.find(current) == chain.end());

	if (current != n) continue;
	if (chain.size() > longestChain) {
	    longestChain = chain.size();
	    bestNumber = smallest;
	}
    }

    std::cout << bestNumber << "\n";
    return 0;
}
