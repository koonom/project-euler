#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <boost/lexical_cast.hpp>

const int SENTINEL = 10000000;
const int N = 40;

int adj[N][N];

// NOTE: Prim's algorithm on adjacency matrix.  Gonna be slow.
int main() {
    for (int i = 0; i < N; ++i) {
	std::string line;
	std::cin >> line;

	int start = 0;
	for (int j = 0; j < N; ++j) {
	    int pos = line.find(',', start);
	    std::string val = (pos == std::string::npos)?
		line.substr(start): line.substr(start, pos - start);
	    adj[i][j] = (val == "-")? SENTINEL: boost::lexical_cast<int>(val);
	    start = pos + 1;
	}
    }

    int sum = 0;
    int totalWeight = 0;
    for (int i = 0; i < N; ++i)
	for (int j = i + 1; j < N; ++j)
	    if (adj[i][j] != SENTINEL) totalWeight += adj[i][j];

    bool spanned[N];
    std::fill_n(spanned, N, false);
    spanned[0] = true;

    for (int k = 0; k < N - 1; ++k) { // Need to span N - 1 more vertices
	int bestWeight = SENTINEL;
	int x, y;

	for (int i = 0; i < N; ++i) {
	    for (int j = i + 1; j < N; ++j) {
		if ((spanned[i] ^ spanned[j]) == 0) continue;
		if (adj[i][j] == SENTINEL) continue;

		if (adj[i][j] < bestWeight) {
		    bestWeight = adj[i][j];
		    if (spanned[i])
			x = i, y = j;
		    else
			x = j, y = i;
		}
	    }
	}

	sum += bestWeight;
	spanned[y] = true;
    }

    std::cout << totalWeight - sum << std::endl;
    return 0;
}
