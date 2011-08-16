#include <cmath>
#include <iostream>
#include <vector>

const int64_t N = 120000;
int64_t square[N + 1];
bool checked[N + 1];

bool isSquare(const int64_t& n) {
    int64_t s = std::sqrt(n);
    return s * s == n;
}

// NOTE: Very primitive algorithm.  Runs in 7m30s 
int main() {
    int64_t sum = 0;
    for (int64_t i = 1; i <= N; ++i) square[i] = i * i;

    std::vector<int64_t> pool;
    pool.reserve(1024);

    int64_t r_ub = N / 3;
    for (int64_t r = 1; r <= r_ub; ++r) {
	pool.clear();
	int64_t q_ub = N - r;
	for (int64_t q = r + 1; q <= q_ub; ++q)
	    if (isSquare(square[q + r] - q * r)) pool.push_back(q);

	int m = pool.size();
	for (int i = 0; i < m; ++i) {
	    int64_t& q = pool[i];
	    for (int j = i + 1; j < m; ++j) {
		int64_t& p = pool[j];
		if (p + q + r > N) break;
		if (checked[p + q + r]) continue;
		if (isSquare(square[p + q] - p * q)) {
		    sum += p + q + r;
		    checked[p + q + r] = true;
		}
	    }
	}
    }

    std::cout << sum << "\n";
    return 0;
}
