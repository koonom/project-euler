#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

const int N = 28123;
int divisorSum[N + 1];
bool decomposable[N + 1];

int main() {
    using namespace std;

    for (int d = 1; d <= N/2; ++d)
	for (int m = 2; d * m <= N; ++m) divisorSum[d * m] += d;

    vector<int> abundantNumbers;
    for (int n = 1; n <= N; ++n)
	if (n < divisorSum[n]) abundantNumbers.push_back(n);

    int size = abundantNumbers.size();
    for (int i = 0; i < size; ++i)
	for (int j = i; j < size; ++j) {
	    int num = abundantNumbers[i] + abundantNumbers[j];
	    if (num <= N) decomposable[num] = true;
	}

    int sum = 0;
    for (int n = 1; n <= N; ++n)
	if (!decomposable[n]) sum += n;

    cout << sum << "\n";
    return 0;
}
