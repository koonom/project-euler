#include <iostream>
#include <unordered_map>

const int SENTINEL = -1;

char letters[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
int values[] = { 1, 5, 10, 50, 100, 500, 1000 };

int romanToInt(char c) {
    for (int i = 0; i < 7; ++i)
	if (c == letters[i]) return values[i];
    return 0;
}

int romanToInt(const std::string& s) {
    int sum = 0, i = 0;
    while (i < s.size()) {
	int j = i + 1;
	while (j < s.size() && s[j] == s[i]) ++j;

	int value = (j - i) * romanToInt(s[i]);
	int ii = romanToInt(s[i]); 
	int jj = j < s.size()? romanToInt(s[j]): 0;

	if (ii < jj) {
	    if ((ii == 1 || ii == 10 || ii == 100) && jj == 10 * ii) sum -= value;
	    else return 0;
	}
	else sum += value;

	i = j;
    }

    return sum;
}

bool intToRoman(int n, int maxIndex, std::string& result) {
    if (maxIndex == 0) return true;
    if (n == 0) return true;

    std::string bestSoFar; 

    if (n > 0) {
	for (int i = 0; i < maxIndex; ++i) {
	    int m = n / values[i], r = n % values[i];

	    if (values[i] <= n) {
		std::string buf(m, letters[i]);
		if (intToRoman(r, i, buf) &&
		    (bestSoFar.empty() || buf.size() < bestSoFar.size())) bestSoFar = buf;
	    }

	    if (i != 0) {
		++m;
		r -= values[i];

		std::string buf(m, letters[i]);
		if (intToRoman(r, i, buf) &&
		    (bestSoFar.empty() || buf.size() < bestSoFar.size())) bestSoFar = buf;
	    }

	}

	result.append(bestSoFar);
    }
    else {
	int i = maxIndex - 2 + maxIndex % 2; 
	int m = (- n) / values[i];
	int r = (- n) % values[i];

	std::string buf(m, letters[i]);

	if (!intToRoman(-r, i, buf)) return false;
	bestSoFar = buf;

	result.insert(0, bestSoFar);
    }

    return true;
    // return !bestSoFar.empty();
}

std::string intToRoman(int n) {
    std::string result;
    intToRoman(n, 7, result); // allow all combinations
    return result;
}

int main() {
    for (int i = 292; i <= 292; ++i) 
	std::cout << i << " " << intToRoman(i) << std::endl;
    //--------------------------------------------------
    // int totalSaved = 0;
    // std::string numeral;
    // while (std::cin >> numeral) {
    // 	int r = romanToInt(numeral);
    // 	std::string newNumeral = intToRoman(r);
    // 	int saved = numeral.size() - newNumeral.size();
    // 	totalSaved += saved;
    // 
    // 	std::cout << numeral << " " << intToRoman(r) << " " << r << " " << saved << std::endl;
    // }
    // 
    // std::cout << totalSaved << "\n";
    //-------------------------------------------------- 
    return 0;
}
