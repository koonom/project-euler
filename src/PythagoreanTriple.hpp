#ifndef PYTHAGOREAN_TRIPLE_HPP
#define PYTHAGOREAN_TRIPLE_HPP

#include <iostream>

class PythagoreanTriple {
protected:
    PythagoreanTriple(int a, int b, int c): a(a), b(b), c(c) { }

public:
    int a, b, c;

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

    int sum() const { return a + b + c; }

    void print(std::ostream& out) const {
	out << "(" << a << "," << b << "," << c << ")";
    }
};

std::ostream& operator<<(std::ostream& out, const PythagoreanTriple& triple) {
    triple.print(out);
    return out;
}

#endif
