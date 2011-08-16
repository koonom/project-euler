#include <iostream>

// NOTE: Recurrence rule!
int numberOfSubRectangles(int m, int n) {
    if (m < n) std::swap(m, n);
    if (n == 1) return m * (m + 1) / 2 + m - 1;

    int sum = 0;
    for (int x = 2 * m - 2, y_lb = 1; x < 2 * m; ++x, ++y_lb)
	for (int y = y_lb; y < 2 * n; y += 2) {
	    int left = std::min(y - 1, x - 1);
	    int right = std::min(2 * n - 1 - y, x - 1);
	    sum += 1 + left + right;

	    for (int l = 1; l <= left; ++l)
		for (int r = 1; r <= right; ++r) 
		    if (x > l + r) ++sum;
	}

    return numberOfSubRectangles(m - 1, n) + m * n * (n + 1) / 2 + sum;
}

const int M = 47, N = 43;

int main() {
    int total = 0;
    for (int m = 1; m <= M; ++m)
	for (int n = 1; n <= N; ++n) total += numberOfSubRectangles(m, n);
    std::cout << total << std::endl;
    return 0;
}
