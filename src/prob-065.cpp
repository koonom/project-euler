#include <iostream>
#include <vector>
#include <gmpxx.h>

#include "ContinuedFraction.hpp"

int main() {
    std::vector<int> seq = { 2 };
    for (int n = 1; seq.size() < 100; ++n) {
	seq.push_back(1);
	seq.push_back(2 * n);
	seq.push_back(1);
    }

    ContinuedFraction fraction(seq);
    mpq_class c = fraction.getConvergent(100);

    int sum = 0;
    std::string number = c.get_num().get_str();
    for (int i = 0; i < number.size(); ++i) sum += number[i] - '0';

    std::cout << sum << "\n";
    return 0;
}
