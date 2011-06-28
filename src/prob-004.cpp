#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;

bool isPalindrome(const string& s) {
    string::const_iterator i = s.begin(), j = s.end();

    while (i <= j)
	if (*i++ != *--j) return false;
    
    return true;
}

int main() {
    int largestPalindrome = 10201; // Let's go from 101 * 101

    for (int i = 999; i >= 100; --i) 
	for (int j = i; j >= 100; --j) {
	    int num = i * j;
	    if (num < largestPalindrome) continue;

	    if (isPalindrome(boost::lexical_cast<string>(num)))
		largestPalindrome = num;
	}

    cout << largestPalindrome << "\n";
    return 0;
}
