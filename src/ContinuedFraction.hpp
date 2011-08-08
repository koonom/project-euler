#ifndef CONTINUED_FRACTION_HPP
#define CONTINUED_FRACTION_HPP

#include <iostream>
#include <vector>
#include <unordered_map>

#include <gmpxx.h>

class ContinuedFraction {
    std::vector<int> quotients; 
    int period;

protected:
    ContinuedFraction(): period(0) {}
    ContinuedFraction(const std::vector<int>& quotients, int period):
	quotients(quotients), period(period) {}

public:
    static ContinuedFraction finiteSequence(const std::vector<int>& sequence) {
	return ContinuedFraction(sequence, 0);
    }

    static ContinuedFraction squareRoot(int n) {
	ContinuedFraction fraction;

	fraction.quotients.push_back(0);
	int r = 0, d = 1;
	while (n - (r - 1) * (r - 1) >= 0) 
	    ++fraction.quotients.back(), --r;
	d = n - r * r;
	r = -r;

	std::unordered_map<int, int> pool;
	for (int i = 0; d != 0; ++i) {
	    int sig = d * n + r;

	    if (pool.find(sig) != pool.end()) {
		fraction.period = i - pool[sig];
		break;
	    }

	    pool[sig] = i;
	    fraction.quotients.push_back(0);
	    while (n - (r - d) * (r - d) >= 0) 
		++fraction.quotients.back(), r -= d;
	    d = (n - r * r) / d;
	    r = -r;
	}

	return fraction;
    }

    int getPeriod() const { return period; }

    int operator[](int n) const {
	return 
	    n < quotients.size()? quotients[n]: 
	    (period == 0)? 0: quotients[(n - quotients.size()) % period + quotients.size() - period];
    }

    mpq_class getConvergent(int n) const {
	if (n == 0) return mpq_class((*this)[0], 1);
	if (n == 1) return mpq_class((*this)[0] * (*this)[1] + 1, (*this)[1]);

	mpq_class beforeLast, last((*this)[0], 1);
	mpq_class current((*this)[0] * (*this)[1] + 1, (*this)[1]);

	for (int i = 2; i <= n; ++i) {
	    beforeLast = last;
	    last = current;
	    current = getNextConvergent(i, beforeLast, last);
	}

	return current;
    }

    mpq_class getNextConvergent(int n, mpq_class c1, mpq_class c2) const {
	int a = (*this)[n];
	return mpq_class(c1.get_num() + a * c2.get_num(),
			 c1.get_den() + a * c2.get_den());
    }

    void print(std::ostream& out) {
	out << "[" << quotients[0];
	if (quotients.size() > 1) {
	    out << ";" << quotients[1];
	    for (int i = 2; i < quotients.size(); ++i) out << "," << quotients[i];
	}
	out << "]";
    }
};

std::ostream& operator<<(std::ostream& out, ContinuedFraction fraction) {
    fraction.print(out);
    return out;
}

class ConvergentGenerator {
    ContinuedFraction fraction;
    mpq_class last[2], current;
    int nc;

public:
    ConvergentGenerator(int n): 
	fraction(ContinuedFraction::squareRoot(n)), nc(0) { }

    const mpq_class& nextConvergent() {
	last[0] = last[1];
	last[1] = current;
	current = (nc == 0 || nc == 1)? fraction.getConvergent(nc):
	    fraction.getNextConvergent(nc, last[0], last[1]);

	++nc;
	return current;
    }
};

#endif
