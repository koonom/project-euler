#include <iostream>

const int N = 80;
int cost[N + 1][N + 1]; // I like sentinels
const int SENTINEL = 1000000;

int main() {
    for (int i = 0; i < N; ++i) 
	for (int j = 0; j < N; ++j) {
	    std::cin >> cost[i][j];
	    std::cin.ignore();
	}

    // Do not place sentinels around the bottom-right
    for (int i = 0; i < N - 1; ++i) cost[N][i] = cost[i][N] = SENTINEL;

    for (int i = N - 1; i >= 0; --i)
	for (int j = N - 1; j >= 0; --j)
	    cost[i][j] += std::min(cost[i + 1][j], cost[i][j + 1]);

    std::cout << cost[0][0] << "\n";
    return 0;
}
