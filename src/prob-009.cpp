#include <iostream>

int main() {
    for (int a = 1; a <= 1000; ++a) {
	for (int b = a + 1; a + b <= 1000; ++b) {
	    int c = 1000 - a - b;
	    if (c < b) continue;

	    if (a * a + b * b == c * c) 
		std::cout << a * b * c << "\n";
	}
    }

    return 0;
}
