#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <iterator>

int main() {
    // I got bored so I rewrite the whole thing
    std::vector<int> lastLevel, level;
    for (int l = 1; std::cin; ++l) {
	for (int i = 0; i < l; ++i) {
	    level.push_back(0);
	    std::cin >> level.back();

	    int left = (i == 0)? 0: lastLevel[i - 1];
	    int right = (i == l - 1)? 0: lastLevel[i];
	    level.back() += std::max(left, right);
	}

	level.swap(lastLevel);
	level.clear();
    }

    std::cout << *std::max_element(lastLevel.begin(), lastLevel.end()) << "\n";
    return 0;
}
