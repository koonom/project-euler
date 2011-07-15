#include <iostream>
#include <unordered_map>
#include <vector>
#include <boost/lexical_cast.hpp>

class ContinuedFraction {
    int head;
    int period;
    std::vector<int> sequence;

public:
    ContinuedFraction(int n): head(0), period(0) {
	int r = 0, d = 1;
	while (n - (r - 1) * (r - 1) >= 0) --r, ++head;
	d = n - r * r;
	r = -r;

	std::unordered_map<int, int> pool;
	for (int i = 0; d != 0; ++i) {
	    int sig = d * n + r;

	    if (pool.find(sig) != pool.end()) {
		period = i - pool[sig];
		break;
	    }

	    pool[sig] = i;
	    sequence.push_back(0);
	    while (n - (r - d) * (r - d) >= 0) ++sequence.back(), r -= d;
	    d = (n - r * r) / d;
	    r = -r;
	}
    }

    int getHead() const { return head; }
    int getPeriod() const { return period; }
    const std::vector<int>& getSequence() const { return sequence; }
};

const int N = 10000;

int main() {
    int numberOfOddPeriods = 0;
    for (int n = 1; n <= N; ++n) 
	if (ContinuedFraction(n).getPeriod() % 2) ++numberOfOddPeriods;

    std::cout << numberOfOddPeriods << "\n";
    return 0;
}
