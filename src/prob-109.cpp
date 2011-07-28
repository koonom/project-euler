#include <iostream>
#include <vector>

const int N = 6;
std::vector<int> scores;

void init() {
    for (int i = 1; i <= 20; ++i) 
	for (int k = 0; k < 3; ++k) scores.push_back((k + 1) * i);
    scores.push_back(25);
    scores.push_back(50);
}

int checkout(int n, int nslots, int lb = 0) {
    if (nslots == 1) { 
	if (n & 1) return 0;
	if (n >= 2 && n <= 40 || n == 50) return 1;
	return 0;
    }

    int sum = 0;
    for (int i = lb; i < scores.size(); ++i) {
	if (n < scores[i]) continue;
	sum += checkout(n - scores[i], nslots - 1, i);
    }
    return sum;
}

int main() {
    init();

    int sum = 0;
    for (int n = 1; n < 100; ++n) 
	sum += checkout(n, 1) + checkout(n, 2) + checkout(n, 3);
    std::cout << sum << "\n";
    return 0;
}
