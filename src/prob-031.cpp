#include <iostream>

int faceValue[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };

int numberOfWays(int n, int coin) {
    if (coin == 0) return 1;

    int result = 0;
    for (int j = 0; j * faceValue[coin] <= n; ++j)
	result += numberOfWays(n - j * faceValue[coin], coin - 1);

    return result;
}

int main() {
    std::cout << numberOfWays(200, 7) << "\n";
    return 0;
}
