#include <iostream>

struct Point {
    int x, y;
};

bool sameSide(Point& l1, Point& l2, Point& p1, Point& p2) {
    Point normal = { l1.y - l2.y, l2.x - l1.x };
    Point p1l1 = { p1.x - l1.x, p1.y - l1.y };
    Point p2l1 = { p2.x - l1.x, p2.y - l1.y };

    int sgn1 = (p1l1.x * normal.x + p1l1.y * normal.y > 0)? 1: -1;
    int sgn2 = (p2l1.x * normal.x + p2l1.y * normal.y > 0)? 1: -1;

    return sgn1 * sgn2 > 0;
}

int main() {
    char duh; 
    Point p[3], o = { 0, 0 };
    int numberOfTriangles = 0;
    while (std::cin >> p[0].x >> duh >> p[0].y >> duh) {
	std::cin >> p[1].x >> duh >> p[1].y >> duh; 
	std::cin >> p[2].x >> duh >> p[2].y;

	if (!sameSide(p[0], p[1], o, p[2])) continue;
	if (!sameSide(p[0], p[2], o, p[1])) continue;
	if (!sameSide(p[1], p[2], o, p[0])) continue;
	++numberOfTriangles;
    }

    std::cout << numberOfTriangles << "\n";
    return 0;
}
