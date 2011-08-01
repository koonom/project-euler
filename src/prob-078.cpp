#include <iostream>
#include <gmpxx.h>

const int N = 1000000;
int p[N + 1];

// NOTE: I'm going to leave my DP solution below (for reference)
int main() {
    p[0] = p[1] = 1;

    for (int n = 2; n <= N; ++n) {
	for (int i = 1; ; ++i) {
	    int m1 = n - i * (3 * i - 1) / 2;
	    int m2 = n - i * (3 * i + 1) / 2;
	    int s = i % 2? 1: -1;

	    if (m1 >= 0) p[n] += s * p[m1];
	    else break;

	    if (m2 >= 0) p[n] += s * p[m2];
	    else break;
	}

	p[n] %= 1000000;

	if (p[n] == 0) {
	    std::cout << n << "\n";
	    break;
	}
    } 

    return 0;
}

//--------------------------------------------------
// DP solution
//-------------------------------------------------- 
const int M = 60000; 
int k[N + 1]; // Enough for k(M, M - 1)

// NOTE: The complexity is linear in space and quadratic in time
int main_DP() {
    for (int i = 0; i <= M; ++i) k[i] = 1;
    
    for (int i = 2; i <= M; ++i) {
	for (int j = i; j <= M; ++j) 
	    k[j] = (k[j] + k[j - i]) % 1000000; // ``mod'' trick
	if (k[i] == 0) {
	    std::cout << i << "\n";
	    break;
	}
    }
    
    return 0;
}

