#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

const int N = 200, SENTINEL = 10000000;
int m[N + 1][N + 1];

// NOTE: Fantastic problem!  Elegant DP solution.
int main() {
    int sum = 0;

    m[1][1] = 0;
    for (int n = 2; n <= N; ++n) {
	for (int k = 1; k < n; ++k) {
	    m[n][k] = SENTINEL;
	    for (int x = 1; x <= n / 2 && n - x >= k; ++x) {
		int a = x, b = k, c = n - x;
		if (a > b) std::swap(a, b);
		int val = m[c][b] - m[b][b] + m[b][a] + 1;
		if (val < m[n][k]) m[n][k] = val;
	    }
	}

	m[n][n] = m[n][1];
	sum += m[n][n];
    }

    std::cout << sum << "\n";
    return 0;
}
