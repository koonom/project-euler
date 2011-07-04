#include <iostream>
#include <unordered_set>

bool eligible(int a, int mask) {
    while (a) {
	if (mask & (1 << (a % 10))) return false;
	mask |= 1 << (a % 10);
	a /= 10;
    }
    return true;
}

int getMask(int n, int mask) {
    while (n) {
	mask |= 1 << (n % 10);
	n /= 10;
    }
    return mask;
}

int main() {
    std::unordered_set<int> seen;
    int sum = 0;
    for (int a = 1; a <= 100; ++a) { // Why 100?
	if (!eligible(a, 0)) continue;
	int mask1 = getMask(a, 0);
	for (int b = 1; b <= 10000 / a; ++b) { // Why 10000 / a?
	    if (!eligible(b, mask1)) continue;
	    int mask2 = getMask(b, mask1);
	    if (!eligible(a * b, mask2) || getMask(a * b, mask2) != 0x3fe) continue;
	    if (seen.find(a * b) != seen.end()) continue;
	    seen.insert(a * b);
	    sum += a * b;
	}
    }

    std::cout << sum << "\n";
    return 0;
}
