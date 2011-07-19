#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

const int M = 50000000;
bool matched[M + 1];

const int N = 10000; // a bit larger than sqrt(M)
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n])
	    for (int m = n + n; m <= N; m += n) composite[m] = true;

    std::vector<int> squares, cubes, fourths;
    int maxS = std::sqrt(M); 
    int maxC = std::exp(std::log(M) / 3);
    int maxF = std::exp(std::log(M) / 4);

    for (int i = 2; i <= maxS; ++i) {
	if (composite[i]) continue;
	squares.push_back(i * i);

	if (i <= maxC)
	    cubes.push_back(i * i * i);
	if (i <= maxF)
	    fourths.push_back(i * i * i * i);
    }

    for (int i = 0; i < fourths.size(); ++i) {
	int left1 = M - fourths[i];
	for (int j = 0; j < cubes.size(); ++j) {
	    if (cubes[j] >= left1) break;
	    int left2 = left1 - cubes[j];
	    for (int k = 0; k < squares.size(); ++k) {
		if (squares[k] >= left2) break;
		matched[fourths[i] + cubes[j] + squares[k]] = true;
	    }
	}
    }

    int numberOfMatches = 0;
    for (int i = 0; i < M; ++i) numberOfMatches += matched[i];

    std::cout << numberOfMatches << "\n";
    return 0;
}
