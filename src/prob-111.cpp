#include <algorithm>
#include <iostream>
#include <string>
#include <gmpxx.h>

bool getNext(std::string& s, char skip) {
    std::string::reverse_iterator j = s.rbegin();
    while (j != s.rend()) {
	*j = '0' + (*j - '0' + 1) % 10;
	bool carry = *j == '0';
	if (*j == skip) {
	    *j = '0' + (*j - '0' + 1) % 10;
	    carry |= *j == '0';
	}

	if (carry) ++j;
	else break;
    }
    
    return j != s.rend();
}

const int N = 10;

// NOTE: It works surprisingly well
int main() {
    mpz_class totalSum = 0;
    for (int d = 0; d < 10; ++d)
	for (int m = N - 1; m >= 1; --m) {
	    mpz_class sumOfPrimes = 0;
	    mpz_class numberOfPrimes = 0;

	    std::string pad(m, '0' + d);
	    std::string pattern;

	    if (d == 0) pattern.append(N - m, '1');
	    else pattern.append(N - m, '0');

	    do {
		int i = 1;
		while (i < pattern.size() && pattern[i] >= pattern[i - 1]) ++i;
		if (i != pattern.size()) continue;

		std::string number = pad + pattern; 
		std::sort(number.begin(), number.end());

		do {
		    if (number[0] == '0') continue;
		    mpz_class n(number);
		    if (mpz_probab_prime_p(n.get_mpz_t(), 5)) sumOfPrimes += n;
		} while (std::next_permutation(number.begin(), number.end()));
	    } while (getNext(pattern, '0' + d));

	    if (sumOfPrimes > 0) {
		totalSum += sumOfPrimes;
		break;
	    }
	}

    std::cout << totalSum << "\n";
    return 0;
}
