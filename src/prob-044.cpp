#include <iostream>
#include <unordered_set>

int main() {
    using namespace std;

    unordered_set<int> pentagonal;

    int minimum = 0;
    int n = 1;
    while (true) {
	int k = n * (3 * n - 1) / 2;

	for (unordered_set<int>::iterator i = pentagonal.begin(); 
	     i != pentagonal.end(); ++i) 
	{
	    if ((k - *i) % 2) continue;

	    int j = *i;
	    int p = (k - j) / 2, q = (k + j) / 2;

	    if (pentagonal.find(p) == pentagonal.end()) continue;
	    if (pentagonal.find(q) == pentagonal.end()) continue;

	    if (minimum && minimum < j) continue;
	    minimum = j;
	}

	if (minimum) break;

	pentagonal.insert(k);
	++n;
    }

    std::cout << minimum << "\n";
    return 0;
}
