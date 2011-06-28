#include <iostream>
#include <bitset>
#include <gmpxx.h>

int main() {
    using namespace std;

    const int N = 2000000;
    bitset<N + 1> prime(0); // indice start from 0
    mpz_class sum = 0;

    for (int p = 2; p <= N; ++p) {
	if (prime.test(p)) continue;

	sum += p;

	int multiple = p + p;
	while (multiple <= N) {
	    prime.set(multiple);
	    multiple += p;
	}
    }

    std::cout << sum << "\n";
    return 0;
}
