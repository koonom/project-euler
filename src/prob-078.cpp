#include <iostream>
#include <gmpxx.h>

const int N = 60000; 
int k[N + 1]; // Enough for k(N, N - 1)

// NOTE: The complexity is linear in space and quadratic in time
// Can it be improved?
int main() {
    for (int i = 0; i <= N; ++i) k[i] = 1;
    
    for (int i = 2; i <= N; ++i) {
	for (int j = i; j <= N; ++j) 
	    k[j] = (k[j] + k[j - i]) % 1000000; // ``mod'' trick
	if (k[i] == 0) {
	    std::cout << i << "\n";
	    break;
	}
    }
    
    return 0;
}
