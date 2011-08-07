#include <iostream>

const int N = 100000000;

bool isReversible(int n) {
    int r = 0;
    if (n % 10 == 0) return false;
    for (int m = n; m; m /= 10) {
	int d = m % 10;
	r = 10 * r + d;
    }
    
    int sum = n + r;
    for (int m = sum; m; m /= 10)
	if (m % 2 == 0) return false;
    return true;
}

int main() {
    int count = 0;
    for (int n = 1; n <= N; ++n)
	if (isReversible(n)) ++count;

    std::cout << count << "\n";
    return 0;
}
