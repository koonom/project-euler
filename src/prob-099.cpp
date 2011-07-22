#include <cmath>
#include <iostream>

int main() {
    int bestLine = -1;
    double bestResult = 0;
    int b, e;
    char duh;

    for (int i = 1; std::cin >> b >> duh >> e; ++i) {
	double result = std::log(b) * e;
	if (result > bestResult) {
	    bestLine = i;
	    bestResult = result;
	}
    }

    std::cout << bestLine << "\n";
    return 0;
}
