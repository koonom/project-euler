#include <algorithm>
#include <iostream>

const int N = 120000;
int rad[N + 1];

int gcd(int m, int n) {
    if (n == 0) return m;
    if (n == 1) return 1;
    return gcd(n, m % n);
}

// NOTE: Not quite satisfactory
int main() {
    for (int n = 2; n <= N; ++n)
	if (!rad[n])
	    for (int m = n; m <= N; m += n)
		if (rad[m]) rad[m] *= n;
		else rad[m] = n;

    rad[1] = 1;

    int sum = 0;
    for (int c = 1; c <= N; ++c) {
	if (rad[c] == c) continue;
	int r = c / rad[c];

	for (int b = c / 2; b < c; ++b) {
	    if (rad[b] > r) continue;

	    int a = c - b;
	    if (rad[a] * rad[b] >= r) continue;

	    int x = rad[c], y = rad[b]; 
	    if (x < y) std::swap(x, y);
	    if (gcd(x, y) > 1) continue;

	    x = rad[c], y = rad[a];
	    if (x < y) std::swap(x, y);
	    if (gcd(x, y) > 1) continue;

	    x = rad[b], y = rad[a];
	    if (x < y) std::swap(x, y);
	    if (gcd(x, y) > 1) continue;

	    sum += c;
	}
    }

    std::cout << sum << "\n";
}
