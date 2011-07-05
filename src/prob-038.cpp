#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;

int testPandigital(int n) {
    int mask = 0;
    string s;

    for (int m = 1; m <= 9; ++m) {
	for (int num = m * n; num > 0; num /= 10) {
	    int digitMask = 1 << num % 10;
	    if (mask & digitMask) return 0;
	    mask |= digitMask;
	}

	s += boost::lexical_cast<string>(m * n);
	if (mask == 0x3fe) return boost::lexical_cast<int>(s);
    }

    return 0;
}

int main() {
    int largestPandigitalNumber = 0;

    for (int n = 1; n < 10000; ++n) {
	int result = testPandigital(n);
	if (result > largestPandigitalNumber) 
	    largestPandigitalNumber = result;
    }

    std::cout << largestPandigitalNumber << "\n";
    return 0;
}
