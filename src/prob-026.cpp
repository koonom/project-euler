#include <string>
#include <iostream>
#include <unordered_map>

int main() {
    int bestD = 0;
    int longestCycle = 0;

    for (int d = 2; d < 1000; ++d) {
	std::unordered_map<int, int> history;
	std::string output;

	int n = 10;
	char c;
	int rep = 0;

	int j = 1;
	while (n != 0) {
	    if (history[n] == 0) history[n] = j;
	    else {
		rep = history[n];
		break;
	    }

	    c = '0' + n / d;
	    n = 10 * (n % d);
	    output += c;
	    ++j;
	}

	if (rep > 0)
	    if (longestCycle < j - rep) {
		bestD = d;
		longestCycle = j - rep;
	    }

	// std::cout << d << " 0." << output << " " << rep << "\n";
    }

    std::cout << bestD << "\n";
    return 0;
}
