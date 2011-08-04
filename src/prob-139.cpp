#include <iostream>
#include <gmpxx.h>

#include "PythagoreanTriple.hpp"

template<typename T>
struct SumLessThan: public std::unary_function<PythagoreanTriple<T>, bool>
{
    T limit;

    SumLessThan(T limit): limit(limit) {}

    bool operator()(const PythagoreanTriple<T>& triple) {
	return triple.sum() < limit;
    }
};

int main() {
    PythagoreanTripleGenerator<mpz_class, SumLessThan<mpz_class>> 
	gen(SumLessThan<mpz_class>(1000000));

    while (gen.hasNext()) {
	std::cout << gen.next() << "\n";
    }

    return 0;
}
