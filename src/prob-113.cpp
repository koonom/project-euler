#include <iostream>
#include <gmpxx.h>

const int N = 100;

mpz_class decreasing[N + 1][10], increasing[N + 1][10];

mpz_class decreasingNumber(int n, int ub) {
    if (n == 0) return 0;
    if (n == 1) return ub - 1 + 1;
    if (decreasing[n][ub] > 0) return decreasing[n][ub];

    mpz_class result = 0; 
    for (int i = 1; i <= ub; ++i) 
	result += decreasingNumber(n - 1, i) + 1; // Note the add one
    return decreasing[n][ub] = result;
}

mpz_class increasingNumber(int n, int lb) {
    if (n == 0) return 0;
    if (n == 1) return 9 - lb + 1;
    if (increasing[n][lb] > 0) return increasing[n][lb];

    mpz_class result = 0;
    for (int i = lb; i <= 9; ++i) 
	result += increasingNumber(n - 1, i);
    return increasing[n][lb] = result;
}

mpz_class nonBouncyNumber(int n) {
    mpz_class sum = 0;
    for (int k = 1; k <= n; ++k) 
	sum += increasingNumber(k, 1) + decreasingNumber(k, 9) - 9;
    return sum;
}

int main() {
    std::cout << nonBouncyNumber(N) << "\n";
    return 0;
}
