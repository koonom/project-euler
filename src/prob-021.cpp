#include <iostream>

const int N = 10000;
int amicableNumber[N + 1];

int main() {
    int sum = 0;
    for (int n = 1; n <= N / 2; ++n)
	for (int m = n + n; m <= N; m += n) amicableNumber[m] += n;

    for (int n = 1; n < N; ++n)
	if (amicableNumber[n] < n && amicableNumber[amicableNumber[n]] == n)
	    sum += n + amicableNumber[n];

    std::cout << sum << "\n";
    return 0;
}
