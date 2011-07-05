#include <iostream>
#include <vector>

const int N = 1000000;
bool composite[N + 1];
int components[N + 1];

int main() {
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n]) 
	    for (int m = n + n; m <= N; m += n) composite[m] = true;

    std::vector<int> primes;
    for (int n = 2; n <= N; ++n)
	if (!composite[n]) primes.push_back(n);

    int numberOfPrimes = primes.size();
    for (int i = 0; i < numberOfPrimes; ++i) {
	int sum = primes[i], j = i; 
	do {
	    if (components[sum] < j - i + 1) components[sum] = j - i + 1;
	    sum += primes[++j];
	} while (sum <= N && j < numberOfPrimes);
    }

    int maximum = 0, bestN = 0;
    for (int n = 2; n <= N; ++n)
	if (!composite[n]) 
	    if (maximum < components[n]) {
		maximum = components[n];
		bestN = n;
	    }

    std::cout << bestN << "\n";
    return 0;
}
