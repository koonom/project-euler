#include <iostream>
#include <string>
#include <gmpxx.h>

int main() {
    int maximumDigitalSum = 0;
    mpz_class n;
    for (int a = 1; a < 100; ++a) 
	for (int b = 1; b < 100; ++b) {
	    mpz_ui_pow_ui(n.get_mpz_t(), a, b);
	    std::string nn = n.get_str();

	    int sum = 0;
	    for (std::string::iterator i = nn.begin(); 
		 i != nn.end(); ++i) sum += *i - '0';

	    if (maximumDigitalSum < sum) maximumDigitalSum = sum;
	}

    std::cout << maximumDigitalSum << "\n";
    return 0;
}
