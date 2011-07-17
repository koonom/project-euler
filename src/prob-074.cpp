#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

const int N = 1000000;
int maxChainSize[N];

// NOTE: Not bad, but still quite unsatisfactory
int main() {
    int factorial[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
    std::unordered_map<int, int> nextNumber;

    int numberOfSixtyChains = 0;

    for (int n = 1; n < N; ++n) {
	std::unordered_set<int> pool;
	for (int m = n; pool.find(m) == pool.end(); ) {
	    pool.insert(m);

	    std::unordered_map<int, int>::iterator iter = nextNumber.find(m);
	    if (iter == nextNumber.end()) {
		int nextM = 0;
		for (int mm = m; mm; mm /= 10) nextM += factorial[mm % 10];
		nextNumber[m] = nextM;
		m = nextM;
	    }
	    else m = iter->second;

	    if (m < n && maxChainSize[m] + pool.size() < 60) {
		maxChainSize[n] = maxChainSize[m];
		break;
	    }
	}

	maxChainSize[n] += pool.size();
	if (maxChainSize[n] == 60) ++numberOfSixtyChains;
    }

    std::cout << numberOfSixtyChains << "\n";
    return 0;
}
