#include <iostream>
#include <string>
#include <unordered_set>
#include <boost/lexical_cast.hpp>

const int N = 100;

int main() {
    std::unordered_set<std::string> stash;

    for (int a = 2; a <= N; ++a) {
	int factors[N + 1];
	std::fill_n(factors, N + 1, 0);

	int r = a;
	for (int n = 2; n <= N; ++n)
	    while (r % n == 0) {
		++factors[n];
		r /= n;
	    }

	for (int b = 2; b <= N; ++b) {
	    std::string rep;
	    for (int n = 2; n <= N; ++n) 
		if (factors[n] > 0) {
		    rep += boost::lexical_cast<std::string>(n) + ":";
		    rep += boost::lexical_cast<std::string>(b * factors[n]) + " ";
		}
	    stash.insert(rep);
	}
    }

    std::cout << stash.size() << "\n";
    return 0;
}
