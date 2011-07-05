#include <iostream>

const int N = 1000000;
int composite[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n) {
	if (composite[n]) continue;
	for (int m = n + n; m <= N; m += n) ++composite[m];
    }

    for (int n = 2; n <= N; ++n) {
	if (composite[n] != 4 || composite[n + 1] != 4 ||
	    composite[n + 2] != 4 || composite[n + 3] != 4) continue;

	std::cout << n << "\n";
	return 0;
    }

    return 0;
}
