#include <iostream>

#include "ContinuedFraction.hpp"

const int N = 10000;

int main() {
    int numberOfOddPeriods = 0;
    for (int n = 1; n <= N; ++n)
	if (ContinuedFraction::squareRoot(n).getPeriod() % 2) ++numberOfOddPeriods;

    std::cout << numberOfOddPeriods << "\n";
    return 0;
}
