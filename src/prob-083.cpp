#include <iostream>

const int N = 80;
int cost[N + 2][N + 2], last[N + 2][N + 2], current[N + 2][N + 2];

const int SENTINEL = 10000000;

int main() {
    for (int i = 1; i <= N; ++i) 
	for (int j = 1; j <= N; ++j) {
	    std::cin >> cost[i][j];
	    std::cin.ignore();
	}

    for (int i = 0; i < N; ++i) cost[i][0] = cost[i][N + 1] = SENTINEL;
    for (int j = 0; j < N; ++j) cost[0][j] = cost[N + 1][j] = SENTINEL;

    for (int i = 0; i <= N + 1; ++i)
	for (int j = 0; j <= N + 1; ++j) last[i][j] = SENTINEL;

    last[N][N] = cost[N][N];
    for (int k = 0; k <= N * N; ++k) {
	bool changed = false;

	for (int i = 1; i <= N; ++i)
	    for (int j = 1; j <= N; ++j) {
		current[i][j] = last[i][j];

		int m1 = std::min(last[i][j - 1], last[i][j + 1]);
		int m2 = std::min(last[i - 1][j], last[i + 1][j]);
		int m = cost[i][j] + std::min(m1, m2);

		if (m < current[i][j]) {
		    changed = true;
		    current[i][j] = m;
		}
	    }

	for (int i = 1; i <= N; ++i)
	    for (int j = 1; j <= N; ++j) last[i][j] = current[i][j];

	if (!changed) break;
    }

    std::cout << last[1][1] << "\n";
    return 0;
}
