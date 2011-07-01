#include <iostream>
#include <vector>

int main() {
    using namespace std;

    const int numberOfElements = 10;
    vector<int> elements;
    vector<int> factorials;

    for (int n = 0; n < numberOfElements; ++n) {
	elements.push_back(n);
	factorials.push_back((n == 0)? 1: factorials[n - 1] * n);
    }

    int N = 1000000 - 1; // indice go from 0

    for (int j = 0; j < numberOfElements; ++j) {
	int factor = factorials[numberOfElements - j - 1];
	int quotient = N / factor;
	vector<int>::iterator iter = elements.begin() + quotient;
	cout << *iter;
	elements.erase(iter);

	N %= factor;
    }

    return 0;
}
