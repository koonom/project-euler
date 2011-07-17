#include <iostream>

const int N = 100; 
int k[N + 1][N + 1]; // Enough for k(N, N - 1)
bool composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n])
	    for (int m = n + n; m <= N; m += n) composite[m] = true;

    //--------------------------------------------------
    // k(0, n) = k(m, 0) = 0             for all m, n
    // k(1, n) = k(m, 1) = 0             for all m, n
    //
    // k(m, n) = k(m, m - 1) + 1                 if n >= m
    //         = \sum_{j = 1 .. n} k(m - j, j)   otherwise
    //-------------------------------------------------- 
    for (int i = 0; i <= N; ++i) k[0][i] = k[i][0] = 0; 
    for (int i = 1; i <= N; ++i) k[1][i] = k[i][1] = 0; 

    for (int m = 2; m <= N; ++m) {
	for (int n = 2; n < m; ++n) // assume k[m][n] set to 0
	    for (int j = 2; j <= n; ++j)
		if (!composite[j]) k[m][n] += k[m - j][j];

	int carry = !composite[m];
	for (int n = m; n <= N; ++n) k[m][n] = k[m][m - 1] + carry;
    }

    int n = 2;
    for (; n <= N; ++n) 
	if (k[n][n - 1] >= 5000) break;

    std::cout << n << "\n";
    return 0;
}
