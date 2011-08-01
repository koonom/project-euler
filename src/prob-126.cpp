#include <algorithm>
#include <iostream>

const int N = 20000;
int c[N + 1];

int main() {
    for (int x = 1; x <= N; ++x) {
	if (6 * x * x > N) break;
	for (int y = x; y <= N; ++y) {
	    if (2 * (2 * x * y + y * y) > N) break;
	    for (int z = y; z <= N; ++z) {
		int n = 2 * (x * y + y * z + x * z);
		for (int i = 1; n <= N; ++i) {
		    ++c[n];
		    n += 4 * (x + y + z) + 8 * (i - 1);
		}
	    }
	}
    }

    int* match = std::find(c + 1, c + N + 1, 1000);
    if (match != c + N + 1) std::cout << match - c << "\n";
    return 0;
}
