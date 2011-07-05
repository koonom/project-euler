#include <iostream>
#include <list>

const int N = 1000000;
bool composite[N + 1];

// NOTE: This piece of code could be further optimized
int main() {
    using namespace std;

    int numberOfCircularPrimes = 0;
    for (int i = 2; i <= N / 2; ++i)
	for (int j = 2 * i; j <= N; j += i) composite[j] = true;

    for (int i = 2; i <= N; ++i) {
	if (composite[i]) continue;

	list<int> digits;
	for (int n = i; n > 0; n /= 10) digits.push_front(n % 10);

	bool isCircular = true;
	for (int run = 1; run < digits.size(); ++run) {
	    digits.push_front(digits.back());
	    digits.pop_back();

	    int newlyFormed = 0;
	    for (list<int>::iterator iter = digits.begin(); iter != digits.end(); ++iter) 
		newlyFormed = 10 * newlyFormed + *iter;

	    if (composite[newlyFormed]) {
		isCircular = false;
		break;
	    }
	}

	if (isCircular) ++numberOfCircularPrimes;
    }

    std::cout << numberOfCircularPrimes << "\n";
    return 0;
}
