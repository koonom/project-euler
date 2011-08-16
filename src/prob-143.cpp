#include <cmath>
#include <iostream>
#include <vector>

const int64_t N = 120000;
int64_t square[N + 1];

bool isSquare(const int64_t& n) {
    int64_t s = std::sqrt(n);
    return s * s == n;
}

int main() {
    int64_t sum = 0;

    for (int64_t i = 1; i <= N; ++i) square[i] = i * i;

    for (int64_t p = 1; p <= N; ++p) {

	int64_t r_ub = std::min(p, N - p + 1);
	for (int64_t r = 1; r < r_ub; ++r) {
	    int64_t b2 = square[p + r] - p * r;
	    if (!isSquare(b2)) continue;

	    int64_t q_lb = r + 1;
	    int64_t q_ub = std::min(r * (2 * r + p) / (p - r), p);
	    q_ub = std::min(q_ub, N - p - r + 1);
	    for (int64_t q = q_lb; q < q_ub; ++q) {
		if (!isSquare(square[p + q] - p * q)) continue;
		if (!isSquare(square[q + r] - q * r)) continue;
		std::cout << p << ' ' << q << ' ' << r << std::endl;
		sum += p + q + r;
	    }
	}

	//--------------------------------------------------
	// int64_t q_ub = std::min(p, N - p + 1);
	// for (int64_t q = 1; q < q_ub; ++q) {
	//     int64_t n = square[p + q] - p * q;
	//     if (!isSquare(n)) continue;
	//-------------------------------------------------- 

	//--------------------------------------------------
	//     int64_t r_lb = (std::sqrt(n + 9 * p * q) - p - q) / 4;
	//     int64_t r_ub = std::min(q, N - p - q + 1);
	//     for (int64_t r = r_lb; r < r_ub; ++r) {
	// 	if (!isSquare(square[p + r] - p * r)) continue;
	// 	if (!isSquare(square[q + r] - q * r)) continue;
	//-------------------------------------------------- 

	//--------------------------------------------------
	// 	std::cout << p << ' ' << q << ' ' << r << std::endl;
	// 	sum += p + q + r;
	//     }
	// }
	//-------------------------------------------------- 
    }

    std::cout << sum << "\n";
    return 0;
}

