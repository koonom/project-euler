#include <algorithm>
#include <iostream>
#include <vector>

int square[100];

int matched(int a, int b) {
    int t[] = { a * 10 + b, b * 10 + a };
    for (int i = 0; i < 2; ++i)
	if (square[t[i]]) return square[t[i]];
    return 0;
}

int main() {
    for (int i = 1; i < 10; ++i) square[i * i] = i;

    std::vector<bool> main(10, false);
    for (int i = 4; i < 10; ++i) main[i] = true;

    int numberOfMatches = 0;

    do {
	std::vector<bool> slave = main;
	while (std::next_permutation(slave.begin(), slave.end())) {
	    int result = 0;
	    for (int i = 0; i < 10; ++i) {
		if (!main[i]) continue;
		for (int j = 0; j < 10; ++j) {
		    if (!slave[j]) continue;

		    result |= (1 << matched(i, j));

		    if (i == 6) result |= (1 << matched(9, j));
		    else if (i == 9) result |= (1 << matched(6, j));

		    if (j == 6) result |= (1 << matched(i, 9));
		    else if (j == 9) result |= (1 << matched(i, 6));
		}
	    }

	    if ((result & 0x3FE) == 0x3FE) ++numberOfMatches;
	}
    } while (std::next_permutation(main.begin(), main.end()));

    std::cout << numberOfMatches << std::endl;
    return 0;
}
