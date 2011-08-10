#include <iostream>

const int N = 2000;
const int N2 = N * N;
int s[N2];

enum Type { ROW, COLUMN, DIAGONAL, ANTIDIAGONAL };

int maxSubsetSum(Type type, int r) {
    int lb, ub, inc;

    switch (type) {
    case ROW:
	lb = r * N; 
	ub = lb + N;
	inc = 1;
	break;
    case COLUMN:
	lb = r;
	ub = lb + N * N;
	inc = N;
	break;
    case DIAGONAL:
	lb = r >= 0? r: -r * N;
	ub = r >= 0? N * N - 1 - r * N: N * N - 1 + r;
	ub += N + 1;
	inc = N + 1;
	break;
    case ANTIDIAGONAL:
	lb = r >= 0? (r + 1) * N - 1: N - 1 + r;
	ub = r >= 0? N * (N - 1) + r: N * (N - 1) + r * N;
	ub += N - 1;
	inc = N - 1;
    }

    int maxsum = 0, maxsofar = 0;
    for (int n = lb; n != ub; n += inc) {
	maxsofar = std::max(maxsofar + s[n], 0);
	maxsum = std::max(maxsum, maxsofar);
    }

    return maxsum;
}

int main() {
    for (int k = 1; k <= N2; ++k) {
	if (k <= 55) {
	    int m = 300007; 
	    for (int j = 0; j < 3; ++j) m = (m * k) % 1000000;
	    s[k - 1] = (100003 - (200003 * k) % 1000000 + m) % 1000000 - 500000;
	}
	else
	    s[k - 1] = (s[k - 25] + s[k - 56] + 1000000) % 1000000 - 500000;
    }

    int best = 0;
    for (int i = 0; i < N; ++i) {
	best = std::max(maxSubsetSum(ROW, i), best);
	best = std::max(maxSubsetSum(COLUMN, i), best);
    }

    for (int i = -N + 1; i < N; ++i) {
	best = std::max(maxSubsetSum(DIAGONAL, i), best);
	best = std::max(maxSubsetSum(ANTIDIAGONAL, i), best);
    }

    std::cout << best << "\n";
    return 0;
}
