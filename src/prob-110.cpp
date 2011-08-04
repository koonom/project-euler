#include <iostream>
#include <gmpxx.h>

// Courtesy of http://oeis.org/A018892
const int LIMIT = 4000000;
const int M = 15;
int primes[M] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 }; 

// We want running1 >= 2 * LIMIT while minimizing running2 (< cut)
mpz_class fit(int index, int ub, mpz_class running1, mpz_class running2, mpz_class cut) {
    if (running2 >= cut) return cut;
    if (running1 >= 2 * LIMIT) return running2;
    if (index == M || ub == 0) return cut;

    for (int i = 0; i < ub; ++i) {
	mpz_class result = fit(index + 1, i + 1, running1 * (2 * i + 1), running2, cut);
	if (result < cut) cut = result;

	running2 *= primes[index];
	if (running2 >= cut) break;
    }

    return cut;
}

int main() {
    mpz_class bestSoFar = 1;
    for (int i = 0; i < M; ++i) bestSoFar *= primes[i];

    std::cout << fit(0, LIMIT - 0.5, 1, 1, bestSoFar) << "\n";
    return 0;
}
