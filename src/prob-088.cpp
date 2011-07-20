#include <cmath>
#include <iostream>
#include <set>
#include <vector>

const int K = 12000;
int minProductSum[K + 1];

void run(int m, int r, int limit, int runningSum, int runningProduct) {
    if (runningProduct - runningSum + m > K) return;

    if (r == m) {
	int k = runningProduct - runningSum + m;
	if (minProductSum[k] == 0 || minProductSum[k] > runningProduct)
	    minProductSum[k] = runningProduct;
	return;
    }

    for (int i = 2; i <= limit; ++i)
	run(m, r + 1, i, runningSum + i, runningProduct * i);
}

// NOTE: This one is really cool.  Next time I wanna try recurrence as well
int main() {
    std::vector<int> divisors;
    for (int numberOfDivisors = 2; numberOfDivisors <= K; ++numberOfDivisors) {
	int l = 1;
	while (++l) {
	    if (std::log(l) + (numberOfDivisors - 1) * std::log(2) > std::log(K + numberOfDivisors + l - 2)) break;
	}

	// std::cerr << numberOfDivisors << std::endl;
	run(numberOfDivisors, 0, l, 0, 1);
    }

    std::set<int> pool;
    for (int k = 2; k <= K; ++k) pool.insert(minProductSum[k]);

    int sum = 0;
    for (std::set<int>::iterator i = pool.begin();
	 i != pool.end(); ++i) sum += *i;

    std::cout << sum << "\n";
    return 0;
}
