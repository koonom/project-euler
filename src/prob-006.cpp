#include <iostream>

int main() {
    int N = 100;
    int sum = 0;
    int sumOfSquares = 0;

    for (int i = 1; i <= N; ++i) {
	sum += i;
	sumOfSquares += i * i;
    }

    std::cout << sum * sum - sumOfSquares << "\n";
    return 0;
}
