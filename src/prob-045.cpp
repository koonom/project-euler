#include <iostream>
#include <unordered_map>
#include <gmpxx.h>

std::string calculate(int lowerBound) {
    std::unordered_map<std::string, int> stash;

    int n = 0;
    while (++n) {
	mpz_class t = n; t *= (n + 1); t /= 2; // beware of over-flow
	mpz_class p = n; p *= (3 * n - 1); p /= 2;
	mpz_class h = n; h *= (2 * n - 1);

	if (stash[t.get_str()] == 2 && t > lowerBound) return t.get_str();

	++stash[t.get_str()];
	++stash[p.get_str()];
	++stash[h.get_str()];
    }
}


int main() {
    std::cout << calculate(40755) << "\n";
    return 0;
}
