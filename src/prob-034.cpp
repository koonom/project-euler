#include <iostream>
#include <iterator>

int factorial[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int digits[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int runningSum = 0;
int sumOfSums = 0;

void chooseDigits(int nslot, int currentDigit) {
    int myDigits[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    if ((nslot == 0 || currentDigit == 10)) {
	if (runningSum < 10) return;

	for (int sum = runningSum; sum > 0; sum /= 10)
	    ++myDigits[sum % 10];

	for (int i = 0; i < 10; ++i)
	    if (digits[i] != myDigits[i]) return;

	sumOfSums += runningSum;
	return;
    }

    for (int p = 0; p <= nslot; ++p) {
	digits[currentDigit] += p;
	runningSum += factorial[currentDigit] * p;

	chooseDigits(nslot - p, currentDigit + 1);

	digits[currentDigit] -= p;
	runningSum -= factorial[currentDigit] * p;
    }
}

int main() {
    chooseDigits(7, 0);
    std::cout << sumOfSums << "\n";
    return 0;
}

