#include <algorithm>
#include <iostream>
#include <gmpxx.h>

int main() {
    using namespace std;

    bool numbers[10];
    fill_n(numbers, 10, true);

    int sum = 0;
    mpz_class n;

    for (int exponent = 1; ; ++exponent) {
	bool good = false;

	for (int i = 1; i < 10; ++i)
	    if (numbers[i]) {
		good = true;
		mpz_ui_pow_ui(n.get_mpz_t(), i, exponent);
		int len = n.get_str().size();

		if (len == exponent) ++sum;
		else if (len < exponent) numbers[i] = false;
	    }

	if (!good) break;
    }

    cout << sum << "\n";
    return 0;
}
