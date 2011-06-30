#include <iostream>

const int N = 10000;
int amicableNumber[N + 1];

int main() {
    int sum = 0;

    for (int n = 1; n < N; ++n)
	for (int i = 1; i <= n/2; ++i)
	    if (n % i == 0) amicableNumber[n] += i;

    for (int n = 1; n < N; ++n)
	if (amicableNumber[n] < n && amicableNumber[amicableNumber[n]] == n)
	    sum += n + amicableNumber[n];

    std::cout << sum << "\n";
    return 0;
}
