#include <iostream>
#include <vector>

#include "PythagoreanTriple.hpp"

const int N = 1500000;
int numberOfTriples[1 + N];

int main() {
    typedef PythagoreanTriple<int> Triple;
    std::vector<Triple> pool;

    if (Triple::root().sum() <= N) {
	pool.push_back(Triple::root());
	
	for (int i = 0; i < pool.size(); ++i) { 
	    int l = pool[i].sum();
	    for (int m = l; m <= N; m += l) ++numberOfTriples[m];
	    for (int j = 1; j <= 3; ++j) {
		Triple newChild = pool[i].child(j);
		if (newChild.sum() <= N) pool.push_back(newChild);
	    }
	}
    }

    int result = 0;
    for (int l = 1; l <= N; ++l)
	if (numberOfTriples[l] == 1) ++result;

    std::cout << result << "\n";
    return 0;
}
