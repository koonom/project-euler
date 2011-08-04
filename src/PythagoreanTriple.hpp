#ifndef PYTHAGOREAN_TRIPLE_HPP
#define PYTHAGOREAN_TRIPLE_HPP

#include <iostream>
#include <queue>

//--------------------------------------------------
// PythagoreanTriple<T>
//-------------------------------------------------- 
template<typename T>
class PythagoreanTriple {
protected:
    PythagoreanTriple(T a, T b, T c): a(a), b(b), c(c) { }

public:
    T a, b, c;

    static PythagoreanTriple root() {
	return PythagoreanTriple(3, 4, 5);
    }

    // Generation using parent/child relationships.  
    // Consult Berggren (1934) or http://www.hbmeyer.de/pythagen.htm
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

    T sum() const { return a + b + c; }

    void print(std::ostream& out) const {
	out << "(" << a << "," << b << "," << c << ")";
    }
};

template<typename T>
bool operator<(const PythagoreanTriple<T>& t1, const PythagoreanTriple<T>& t2) {
    return t1.a < t2.a || t1.a == t2.a && t1.b < t2.b;
}

template<typename T>
bool operator>(const PythagoreanTriple<T>& t1, const PythagoreanTriple<T>& t2) {
    return t1.a > t2.a || t1.a == t2.a && t1.b > t2.b;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const PythagoreanTriple<T>& triple) {
    triple.print(out);
    return out;
}

//--------------------------------------------------
// PythagoreanTripleGenerator<T>
//-------------------------------------------------- 
template<typename T>
class PythagoreanTripleGenerator {
    std::priority_queue<
	PythagoreanTriple<T>, 
	std::vector<PythagoreanTriple<T>>, 
	std::greater<PythagoreanTriple<T>> > pq;

public:
    PythagoreanTripleGenerator() {
	pq.push(PythagoreanTriple<T>::root());
    }

    PythagoreanTriple<T> next() {
	PythagoreanTriple<T> top = pq.top();
	pq.pop();

	for (int i = 1; i <= 3; ++i) pq.push(top.child(i));
	return top;
    }
};

#endif
