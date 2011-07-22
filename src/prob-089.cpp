#include <iostream>
#include <unordered_map>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>

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

bool intToRoman(int n, int lb, int ub, std::string& result) {
    std::string head = boost::str(boost::format("%d (%d, %d)") % n % lb % ub);

    if (n == 0) return true;

    std::string bestSoFar;

    if (n > 0) {
	for (int i = lb; i < ub; ++i) {
	    // Case 1: q...q + r
	    int q = n / values[i];
	    int r = n % values[i];

	    if (n >= values[i]) {
		std::string buf(q, letters[i]);
		std::cerr << head << " 1: " << result << '|' << buf << " " << r << std::endl;
		if (!intToRoman(r, lb, i, buf)) continue;
		if (bestSoFar.empty() || bestSoFar.size() > buf.size()) {
		    bestSoFar = buf;
		    std::cerr << head << " [1] " << bestSoFar << std::endl;
		}
	    }

	    // Case 2: q...q + r q
	    if (r > 0) {
		r -= values[i]; // < 0

		std::string buf(q, letters[i]), buf2(1, letters[i]);
		std::cerr << head << " 2: " << result << '|' << buf << ' ' << r << ' ' << buf2 << std::endl;
		if (!intToRoman(r, lb, i % 2 + i - 2, buf2)) continue; // abuse, note 2
		buf += buf2;

		if (bestSoFar.empty() || bestSoFar.size() > buf.size()) {
		    bestSoFar = buf;
		    std::cerr << head << " [2] " << bestSoFar << std::endl;
		}
	    }
	}

	result.append(bestSoFar);
    }
    else {
	int nn = -n;

	if (ub != 0 && ub != 2 && ub != 4) return false;
	if (nn > values[ub]) return false; // Key

	int q = nn / values[ub], r = nn % values[ub];

	if (r > 0) {
	    q += 1;
	    r -= values[ub];
	}

	// Case 3:  qqq ??? rrr
	std::string buf, prefix(q, letters[ub]);
	std::cerr << head << " 3: " << prefix << " (" << result << ") " << r << std::endl;
	if (!intToRoman(-r, lb, ub + 1, buf)) return false; // -r > 0

	bestSoFar = prefix + buf;
	result.insert(0, prefix);
	result.append(buf);
    }

    return !bestSoFar.empty();
}
    

std::string intToRoman(int n) {
    std::string result;
    intToRoman(n, 0, 7, result); // allow all combinations
    return result;
}

int main() {
    int totalSaved = 0;
    std::string numeral;

    while (std::cin >> numeral) {
	int r;

	if (numeral[0] >= '0' && numeral[0] <= '9') {
	    int r = boost::lexical_cast<int>(numeral);

	    std::cout << r << " " << intToRoman(r) << std::endl;
	}
	else {
	    int r = romanToInt(numeral);
	    std::string newNumeral = intToRoman(r);
	    bool same = r == romanToInt(newNumeral);
	    int saved = numeral.size() - newNumeral.size();
	    totalSaved += saved;
	
	    std::cout << numeral << " " << newNumeral << (same? " ": "* ") << r << " " << saved << std::endl;
	}
    }
    
    std::cout << totalSaved << "\n";
    return 0;
}
