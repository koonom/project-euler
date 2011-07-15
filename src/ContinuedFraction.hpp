#ifndef CONTINUED_FRACTION_HPP
#define CONTINUED_FRACTION_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include <gmpxx.h>

class ContinuedFraction {
    std::vector<int> sequence;
    int period;

public:
    ContinuedFraction(int n): period(0) {
	sequence.push_back(0);
	int r = 0, d = 1;
	while (n - (r - 1) * (r - 1) >= 0) ++sequence.back(), --r;
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

    ContinuedFraction(const std::vector<int>& sequence, int period = 0): 
	sequence(sequence), period(period) {} // shallow copy might suffice

    int getPeriod() const { return period; }
    const std::vector<int>& getSequence() const { return sequence; }

    int operator[](int n) const {
	return 
	    n < sequence.size()? sequence[n]: 
	    (period == 0)? 0: sequence[(n - sequence.size()) % period + sequence.size() - period];
    }

    mpq_class getConvergent(int n) const {
	mpq_class q(0);
	for (int d = n - 1; d >= 1; --d) {
	    q += (*this)[d];
	    mpq_inv(q.get_mpq_t(), q.get_mpq_t());
	}
	q += (*this)[0];
	return q;
    }
};

#endif
