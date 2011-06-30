#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
    using namespace std;

    cerr << 
	"This program needs data from the Web.  "
	"Try:\n"
	"  $ curl http://projecteuler.net/project/names.txt | ./prob-022\n";

    string oneline;
    cin >> oneline;

    vector<string> names;
    int openQuotePos = 0, closeQuotePos = -1;

    while (true) {
	openQuotePos = oneline.find('"', closeQuotePos + 1);
	if (openQuotePos == string::npos) break;

	closeQuotePos = oneline.find('"', openQuotePos + 1);
	names.push_back(oneline.substr(openQuotePos + 1, closeQuotePos - openQuotePos - 1));
    }

    stable_sort(names.begin(), names.end());

    int sum = 0;
    for (int i = 0; i < names.size(); ++i) {
	string& name = names[i];

	int alphabetSum = 0;
	for (string::iterator it = name.begin(); it != name.end(); ++it) 
	    alphabetSum += 1 + (*it) - 'A';

	sum += alphabetSum * (i + 1);
    }

    cout << sum << "\n";
    return 0;
}
