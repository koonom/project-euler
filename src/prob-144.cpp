#include <iostream>

struct Vector2D {
    double x, y;

    Vector2D(double x, double y): x(x), y(y) {}
};

double operator*(const Vector2D& u, const Vector2D& v) {
    return u.x * v.x + u.y * v.y;
}

Vector2D operator+(const Vector2D& u, const Vector2D& v) {
    return Vector2D(u.x + v.x, u.y + v.y);
}

Vector2D operator-(const Vector2D& u, const Vector2D& v) {
    return Vector2D(u.x - v.x, u.y - v.y);
}

Vector2D operator*(double r, const Vector2D& v) {
    return Vector2D(r * v.x, r * v.y);
}

std::ostream& operator<<(std::ostream& out, const Vector2D& v) {
    return out << "(" << v.x << "," << v.y << ")";
}


// NOTE: Courtesy of http://en.wikipedia.org/wiki/Reflection_(mathematics)
int main() {
    Vector2D u(1.4 - 0, -9.6 - 10.1);
    double x = 1.4, y = -9.6;
    int numberOfBounces = 0;

    do {
	++numberOfBounces;

	Vector2D l(y, -4 * x);
	Vector2D v = (2.0 * (u * l) / (l * l)) * l - u;
	double t = -(8.0 * v.x * x + 2.0 * v.y * y) / (4.0 * v.x * v.x + v.y * v.y);

	x += t * v.x;
	y += t * v.y;
	u = v;
    } while (x > 0.01 || x < -0.01 || y - 10.0 > 0.1 || 10.0 - y > 0.1);

    std::cout << numberOfBounces << "\n";
    return 0;
}
