#include <iostream>

int main() {
    int f[2] = { 0, 1 };
    int f_new = f[0] + f[1];
    int sum = 0;

    while (f_new < 4000000) {
	if ((f_new & 1) == 0) sum += f_new;

	f[0] = f[1];
	f[1] = f_new;
	f_new += f[0];
    }

    std::cout << sum << "\n";
    return 0;
}
