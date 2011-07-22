#include <iostream>

const int N = 50;

bool nextPoint(int& x, int& y) {
    y = (y + 1) % (N + 1);
    if (y == 0) {
	x = (x + 1) % (N + 1);
	if (x == 0) return false;
    }
    return true;
}

int main() {
    int numberOfRightAngles = 0;
    int x1 = 0, y1 = 1;
    do {
	int x2 = x1, y2 = y1;
	while (nextPoint(x2, y2)) {
	    if (x1 * x2 + y1 * y2 == 0 ||
		(-x1) * (x2 - x1) + (-y1) * (y2 - y1) == 0 ||
		(-x2) * (x1 - x2) + (-y2) * (y1 - y2) == 0) ++numberOfRightAngles;
	}
    } while (nextPoint(x1, y1));

    std::cout << numberOfRightAngles << "\n";
    return 0;
}
