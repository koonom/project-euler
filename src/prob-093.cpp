#include <algorithm>
#include <iostream>
#include <unordered_set>

bool good(double n) {
    return n > 0 && int(n) == n;
}

void solve2(double a, double b, std::unordered_set<int>& k) {
    if (good(a + b)) k.insert(a + b);
    if (good(a - b)) k.insert(a - b);
    if (good(a * b)) k.insert(a * b);
    if (b && good(a / b)) k.insert(a / b);
}


void solve3(double a, double b, double c, std::unordered_set<int>& k) {
    solve2(a + b, c, k);
    solve2(a - b, c, k);
    solve2(a * b, c, k);
    if (b) solve2(a / b, c, k);
    solve2(a, b + c, k);
    solve2(a, b - c, k);
    solve2(a, b * c, k);
    if (c) solve2(a, b / c, k);
}

void solve4(double a, double b, double c, double d, std::unordered_set<int>& k) {
    solve3(a + b, c, d, k);
    solve3(a - b, c, d, k);
    solve3(a * b, c, d, k);
    if (b) solve3(a / b, c, d, k);
    solve3(a, b + c, d, k);
    solve3(a, b - c, d, k);
    solve3(a, b * c, d, k);
    if (c) solve3(a, b / c, d, k);
    solve3(a, b, c + d, k);
    solve3(a, b, c - d, k);
    solve3(a, b, c * d, k);
    if (d) solve3(a, b, c / d, k);
}

int main() {
    int best, largest = 0;
    for (int a = 1; a < 10; ++a)
	for (int b = a + 1; b < 10; ++b)
	    for (int c = b + 1; c < 10; ++c)
		for (int d = c + 1; d < 10; ++d) {
		    std::unordered_set<int> k;
		    int n[] = { a, b, c, d };

		    do {
			solve4(n[0], n[1], n[2], n[3], k);
		    } while (std::next_permutation(n, n + 4));

		    int i = 1;
		    while (k.find(i) != k.end()) ++i;

		    if (largest < i - 1) {
			largest = i - 1;
			best = 1000 * a + 100 * b + 10 * c + d;
		    }
		}

    std::cout << best << "\n";
    return 0;
}
