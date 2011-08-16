#include <cmath>
#include <iostream>

const int64_t N = 120000;
int64_t square[N + 1];

bool isSquare(const int64_t& n) {
    int64_t s = std::sqrt(n);
    return s * s == n;
}

int main() {
    int64_t sum = 0;
    double ratio = 1 + std::sqrt(3);

    for (int64_t i = 1; i <= N; ++i) square[i] = i * i;

    int64_t r_ub = N / 3;
    for (int64_t r = 1; r <= r_ub; ++r) {
	// int64_t q_ub = std::min((N - r) / 2 + 1, int64_t(std::ceil(r * ratio)));
	int64_t q_ub = (N - r) / 2 + 1;
	for (int64_t q = r + 1; q <= q_ub; ++q) {
	    int64_t a2 = square[q + r] - q * r;
	    if (!isSquare(a2)) continue;

	    // int64_t p_ub = std::min(N - r - q, (2 * square[r] + r * q) / (q - r));
	    int64_t p_ub = N - r - q;
	    for (int64_t p = q + 1; p <= p_ub; ++p) {
		int64_t b2 = square[p + r] - p * r;
    		if (!isSquare(b2)) continue;

		int64_t c2 = square[p + q] - p * q;
    		if (!isSquare(c2)) continue;

		// int64_t a = std::sqrt(a2); 
		// int64_t b = std::sqrt(b2);
		// if (c2 >= a2 + b2 + a * b) continue;

    		sum += p + q + r;
    		std::cout << r << ' ' << q << ' ' << p << ' ' << p + q + r << ' ' << sum << "\n";
	    }
	}
    }

    //--------------------------------------------------
    // for (int64_t p = 1; p <= N; ++p) {
    // 
    // 	int64_t r_ub = std::min(p, N - p + 1);
    // 	for (int64_t r = 1; r < r_ub; ++r) {
    // 	    int64_t b2 = square[p + r] - p * r;
    // 	    if (!isSquare(b2)) continue;
    // 
    // 	    int64_t q_lb = r + 1;
    // 	    int64_t q_ub = std::min(r * (2 * r + p) / (p - r), p);
    // 	    q_ub = std::min(q_ub, N - p - r + 1);
    // 	    for (int64_t q = q_lb; q < q_ub; ++q) {
    // 		if (!isSquare(square[p + q] - p * q)) continue;
    // 		if (!isSquare(square[q + r] - q * r)) continue;
    // 		std::cout << p << ' ' << q << ' ' << r << std::endl;
    // 		sum += p + q + r;
    // 	    }
    // 	}
    // }
    //-------------------------------------------------- 

    std::cout << sum << "\n";
    return 0;
}

