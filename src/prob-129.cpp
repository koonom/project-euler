#include <iostream>
#include <gmpxx.h>

const int N = 1000000;
int main() {
    for (int i = N + 1; ; i += 2) {
	if (i % 5 == 0) continue;

	int j = 1, n = 1;
	while ((n %= i) > 0) {
	    n *= 10;
	    ++n;
	    ++j;
	}
	
	if (j > N) {
	    std::cout << i << "\n";
	    break;
	}
    }
    return 0;
}
