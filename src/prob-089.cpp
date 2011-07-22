#include <iostream>
#include <unordered_map>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

char letters[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
int values[] = { 1, 5, 10, 50, 100, 500, 1000 };

std::string ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X" };
std::string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C" };
std::string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M" };

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
	    if (ii != 1 && ii != 10 & ii != 100 && jj > 10 * ii) return 0;
	    if (j + 1 < s.size() && s[j + 1] == s[j]) return 0;

	    sum += jj - value;
	    i = j + 1;
	}
	else {
	    sum += value;
	    i = j;
	}
    }

    return sum;
}

std::string intToRoman(int n) {
    int m = n / 1000, c = n / 100 % 10, x = n / 10 % 10, i = n % 10;
    std::string result;
    result.append(m, 'M').append(hundreds[c]).append(tens[x]).append(ones[i]);
    return result;
}

int main() {
    int totalSaved = 0;
    std::string numeral;

    while (std::cin >> numeral) {
	std::string newNumeral = intToRoman(romanToInt(numeral));
	totalSaved += numeral.size() - newNumeral.size();
    }
    
    std::cout << totalSaved << "\n";
    return 0;
}
