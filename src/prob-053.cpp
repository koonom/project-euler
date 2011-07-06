#include <iostream>

const int N = 100;
int choose[N + 1][N + 1];

const int BOUND = 1000000;

int main() {
    int count = 0;

    for (int n = 1; n <= N; ++n) {
	choose[n][0] = choose[n][n] = 1;
	for (int r = 1; r < n; ++r) {
	    choose[n][r] = choose[n - 1][r] + choose[n - 1][r - 1];
	    if (choose[n][r] >= BOUND) {
		++count;
		choose[n][r] = BOUND;
	    }
	}
    }

    std::cout << count << "\n";
    return 0;
}
