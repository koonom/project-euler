#include <iostream>

const int N = 80;
int cost[N + 2][N], last[N + 2], current[N + 2]; // I like two-way sentinels

const int SENTINEL = 1000000;

int main() {
    for (int i = 1; i <= N; ++i) 
	for (int j = 0; j < N; ++j) {
	    std::cin >> cost[i][j];
	    std::cin.ignore();
	}

    // Place sentinels at the top and the bottom
    for (int j = 0; j < N; ++j) cost[0][j] = cost[N + 1][j] = SENTINEL;

    for (int j = N - 2; j >= 0; --j) {
	for (int i = 0; i <= N + 1; ++i) 
	    last[i] = cost[i][j] + cost[i][j + 1];

	for (int k = 0; k < N; ++k) {
	    for (int i = 1; i <= N; ++i) {
		current[i] = last[i];
		int m = cost[i][j] + std::min(last[i - 1], last[i + 1]);
		if (m < current[i]) current[i] = m;
	    }

	    for (int i = 1; i <= N; ++i) last[i] = current[i];
	}

	for (int i = 1; i <= N; ++i) cost[i][j] = last[i];
    }

    int minSum = cost[1][0];
    for (int i = 1; i <= N; ++i)
	if (cost[i][0] < minSum) minSum = cost[i][0];

    std::cout << minSum << "\n";
    return 0;
}
