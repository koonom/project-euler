#include <iostream>
#include <unordered_map>
#include <vector>
#include <boost/lexical_cast.hpp>

#include "ContinuedFraction.hpp"

const int N = 10000;

int main() {
    int numberOfOddPeriods = 0;
    for (int n = 1; n <= N; ++n) 
	if (ContinuedFraction(n).getPeriod() % 2) ++numberOfOddPeriods;

    std::cout << numberOfOddPeriods << "\n";
    return 0;
}
