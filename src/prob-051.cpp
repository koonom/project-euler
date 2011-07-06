#include <iostream>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>

const int N = 1000000;
bool composite[N + 1];

int main() {
    using namespace std;

    composite[0] = composite[1] = true;
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n])
	    for (int m = n + n; m <= N; m += n) composite[m] = true;
    
    for (int n = 2; n <= N; ++n) {
	if (composite[n]) continue;
	
	int digits[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int m = n; m > 0; m /= 10) ++digits[m % 10];

	for (int i = 0; i < 10; ++i) {
	    if (!digits[i]) continue;

	    int count = 1;
	    char oldDigit = '0' + i;
	    for (char newDigit = '0'; newDigit <= '9'; ++newDigit) {
		if (newDigit == oldDigit) continue;

		string number = boost::lexical_cast<string>(n);
		if (newDigit == '0' && number[0] == oldDigit) continue;

		for (int k = 0; k < number.size(); ++k)
		    if (number[k] == oldDigit) number[k] = newDigit;

		int mm = boost::lexical_cast<int>(number);
		if (!composite[mm]) ++count;
	    }

	    if (count == 8) {
		cout << n << "\n";
		return 0;
	    }
	}
    }

    return 0;
}
