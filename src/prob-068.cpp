#include <algorithm>
#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

const int N = 5;
const int NDIGITS = 16;

int main() {
    std::string bestResult;
    int seats[2 * N];
    for (int i = 0; i < 2 * N; ++i) seats[i] = i + 1;

    do {
	bool good = true;
	int sum = seats[0] + seats[N] + seats[N + 1]; 
	for (int i = 0; i < N; ++i) 
	    if (seats[i] + seats[i + N] + seats[(i + 1) % N + N] != sum) {
		good = false;
		break;
	    }

	if (!good) continue;

	int start = 0;
	for (int i = 1; i < N; ++i) 
	    if (seats[i] < seats[start]) start = i;

	std::string result;
	for (int i = 0; i < N; ++i) {
	    int j = (start + i) % N;
	    result += boost::lexical_cast<std::string>(seats[j]);
	    result += boost::lexical_cast<std::string>(seats[j + N]);
	    result += boost::lexical_cast<std::string>(seats[(j + 1) % N + N]);
	}

	if (result.size() > bestResult.size() || 
	    result.size() == NDIGITS && result > bestResult)
	    bestResult = result;

    } while (std::next_permutation(seats, seats + 2 * N));

    std::cout << bestResult << "\n";
    return 0;
}
