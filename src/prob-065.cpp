#include <iostream>
#include <vector>
#include <gmpxx.h>

int main() {
    std::vector<int> seq = { 2 };
    for (int n = 1; seq.size() < 100; ++n) {
	seq.push_back(1);
	seq.push_back(2 * n);
	seq.push_back(1);
    }

    int ndigits = 99; // the 100th term
    mpq_class n(0);
    for (int d = ndigits; d >= 1; --d) {
	n += seq[d];
	mpq_inv(n.get_mpq_t(), n.get_mpq_t());
    }

    n += seq[0];

    int sum = 0;
    std::string number = n.get_num().get_str();
    for (int i = 0; i < number.size(); ++i) sum += number[i] - '0';

    std::cout << sum << "\n";
    return 0;
}
