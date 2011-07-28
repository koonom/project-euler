#include <iostream>
#include <queue>
#include <gmpxx.h>

// Shameless copy
class PythagoreanTriple {
protected:
    PythagoreanTriple(mpz_class a, mpz_class b, mpz_class c): a(a), b(b), c(c) { }

public:
    mpz_class a, b, c;

    static PythagoreanTriple root() {
	return PythagoreanTriple(3, 4, 5);
    }

    //--------------------------------------------------
    // Generation using parent/child relationships.  
    // Consult Berggren (1934) or http://www.hbmeyer.de/pythagen.htm
    //-------------------------------------------------- 
    PythagoreanTriple child(int n) const {
	switch (n) {
	case 1:
	    return PythagoreanTriple(a - 2 * b + 2 * c, 
				     2 * a - b + 2 * c, 
				     2 * a - 2 * b + 3 * c);
	case 2:
	    return PythagoreanTriple(-2 * a + b + 2 * c, 
				     - a + 2 * b + 2 * c, 
				     - 2 * a + 2 * b + 3 * c);
	case 3:
	    return PythagoreanTriple(2 * a + b + 2 * c, 
				     a + 2 * b + 2 * c, 
				     2 * a + 2 * b + 3 * c);
	default:
	    throw 0;
	}
    }

    mpz_class sum() const { return a + b + c; }

    void print(std::ostream& out) const {
	out << "(" << a << "," << b << "," << c << ")";
    }
};

bool operator<(const PythagoreanTriple& t1, const PythagoreanTriple& t2) {
    return t1.a < t2.a || t1.a == t2.a && t1.b < t2.b;
}

bool operator>(const PythagoreanTriple& t1, const PythagoreanTriple& t2) {
    return t1.a > t2.a || t1.a == t2.a && t1.b > t2.b;
}

std::ostream& operator<<(std::ostream& out, const PythagoreanTriple& triple) {
    triple.print(out);
    return out;
}

// Shameless copy from Problem 075
const int N = 400000, LIMIT = 1000;
int numberOfSolutions[N + 1];

int main() {
    std::priority_queue<PythagoreanTriple, 
	std::vector<PythagoreanTriple>, std::greater<PythagoreanTriple> > pool;
    pool.push(PythagoreanTriple::root());

    int lastChecked = 0; // the greatest verified N so far

    while (!pool.empty()) {
	PythagoreanTriple top = pool.top();
	pool.pop();

	int a = top.a.get_ui();
	for (int m = a; m <= 2 * N; m += a)
	    if ((m & 1) == 0) ++numberOfSolutions[m >> 1];

	if (top.b <= 2 * N) {
	    int b = top.b.get_ui();
	    for (int m = b; m <= 2 * N; m += b)
		if ((m & 1) == 0) ++numberOfSolutions[m >> 1];
	}

	for (int i = lastChecked + 1; i < a / 2; ++i)
	    if (numberOfSolutions[i] >= LIMIT) {
		std::cout << i << "\n";
		return 0;
	    }

	lastChecked = a / 2 - 1;

	for (int j = 1; j <= 3; ++j) {
	    PythagoreanTriple child = top.child(j);
	    if (child.a > 2 * N) break;
	    pool.push(top.child(j));
	}
    }

    return 0;
}
