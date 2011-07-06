#include <iostream>
#include <string>
#include <gmpxx.h>
#include <boost/lexical_cast.hpp>

using namespace std;

bool checkPalindromic(int n, int nruns) {
    mpz_class nn = n;
    for (int i = 0; i < nruns; ++i) {
	string m = nn.get_str();
	string::reverse_iterator first = m.rbegin();
	while (*first == '0') ++first;

	nn += mpz_class(string(first, m.rend()));
	m = nn.get_str();

	int i = 0, j = m.size() - 1; 
	while (i < j && m[i] == m[j]) ++i, --j;
	if (i >= j) return true;
    }

    return false;
}

int main() {
    int numberOfLychrelNumbers = 0;
    for (int n = 1; n < 10000; ++n) 
	if (!checkPalindromic(n, 50)) ++numberOfLychrelNumbers;
    cout << numberOfLychrelNumbers << "\n";
    return 0;
}
