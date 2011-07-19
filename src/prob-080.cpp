#include <iostream>
#include <gmpxx.h>

int main() {
    int totalSum = 0;

    for (int n = 1; n <= 100; ++n) {
	mpf_class s(n, 500);
	mpf_sqrt(s.get_mpf_t(), s.get_mpf_t());
	mp_exp_t ex;

	std::string number = s.get_str(ex, 10, 120);
	if (number.size() < 100) continue;
	number.resize(100);

	int sum = 0;
	for (int i = 0; i < number.size(); ++i) sum += number[i] - '0';
	totalSum += sum;
    }

    std::cout << totalSum << "\n";
    return 0;
}
