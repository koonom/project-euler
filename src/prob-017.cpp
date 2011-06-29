#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

string numberToString(int n) {
    if (n > 1000 || n < 1) return "dunno";

    if (n == 1000) 
	return "one thousand";

    vector<string> ones = {
	"", "one", "two", "three", "four", "five", "six", "seven", 
	"eight", "nine", "ten", "eleven", "twelve", "thirteen", 
	"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", 
	"nineteen"
    };

    vector<string> tens = {
	"", "", "twenty", "thirty", "forty", "fifty", "sixty", 
	"seventy", "eighty", "ninety" 
    };

    int h = n / 100, t = (n - h * 100) / 10, o = n % 10;
    string hundreds, rest;

    if (h >= 1) 
	hundreds = ones[h] + " hundred";

    if (t < 2) 
	rest = ones[t * 10 + o];
    else {
	rest = tens[t];
	if (!rest.empty()) rest += " ";
	rest += ones[o];
    }

    if (hundreds.empty()) return rest;
    else if (rest.empty()) return hundreds;
    else return hundreds + " and " + rest;

    return "-";
}

int main() {
    int numberOfChars = 0;

    for (int i = 1; i <= 1000; ++i) {
	string num = numberToString(i);
	for (string::iterator it = num.begin(); it != num.end(); ++it)
	    if (isalpha(*it)) ++numberOfChars;
    }

    cout << numberOfChars << "\n";
    return 0;
}
