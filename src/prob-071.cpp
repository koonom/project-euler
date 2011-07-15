#include <iostream>
#include <gmpxx.h>

const int D = 1000000;

int main() {
    mpq_class l(2, 5);

    for (int d = 9; d <= D; ++d) {
	int n = 3 * d / 7;
	if (d % 7 == 0) --n;

	mpq_class ll(n, d);
	if (ll > l) l = ll;
    }

    std::cout << l.get_num() << "\n";
    return 0;
}
