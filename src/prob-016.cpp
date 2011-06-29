#include <iostream>
#include <string>
#include <gmpxx.h>
#include <boost/lexical_cast.hpp>

int main() {
    mpz_class n;
    mpz_ui_pow_ui(n.get_mpz_t(), 2, 1000);

    std::string result = n.get_str();

    int sum = 0;
    for (std::string::iterator i = result.begin(); i != result.end(); ++i)
	sum += boost::lexical_cast<int>(*i);

    std::cout << sum << "\n";
    return 0;
}
