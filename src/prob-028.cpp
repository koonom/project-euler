#include <iostream>
#include <gmpxx.h>

int main() {
    mpz_class sum = 1, val = 1; // Go from level 1
    for (int l = 3; l <= 1001; l += 2)
	for (int j = 0; j < 4; ++j) {
	    val += l - 1;
	    sum += val;
	}

    std::cout << sum << "\n";
    return 0;
}
