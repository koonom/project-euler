#include <iostream>
#include <string>
#include <gmpxx.h>
#include <boost/lexical_cast.hpp>

int main() {
    mpz_class f;
    mpz_fac_ui(f.get_mpz_t(), 100);

    int sum = 0;
    std::string num = f.get_str();
    for (std::string::iterator i = num.begin(); i != num.end(); ++i)
	sum += boost::lexical_cast<int>(*i);

    std::cout << sum << "\n";
    return 0;
}
