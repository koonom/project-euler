#include <iostream>

int digitHash(int n) {
    int digits[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int m = n; m; m /= 10) ++digits[m % 10];

    int running = 0;
    for (int i = 0; i < 10; ++i)
	while (digits[i]--) running = 10 * running + i;

    return running;
}

int main() {
    for (int n = 1; ; ++n) {
	int code = digitHash(n);
	if (digitHash(2 * n) != code) continue;
	if (digitHash(3 * n) != code) continue;
	if (digitHash(4 * n) != code) continue;
	if (digitHash(5 * n) != code) continue;
	if (digitHash(6 * n) != code) continue;

	std::cout << n << "\n";
	break;
    }

    return 0;
}
