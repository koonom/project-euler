#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <sstream>
#include <vector>
#include <boost/lexical_cast.hpp>

//--------------------------------------------------
// Shameless copy from Problem 103
//-------------------------------------------------- 
template<typename Iterator>
void reset(Iterator first, Iterator last) {
    std::fill(first, last, 0);
}

template<typename Iterator>
bool next(Iterator first, Iterator last) {
    bool eligible = false;

    do {
	Iterator j = last;
	while (--j >= first)
	    if ((*j = (*j + 1) % 3) > 0) break;

	if (j < first) return false;

	int l = 0;
	for (Iterator i = first; i != last; ++i) {
	    l |= (1 << *i);
	    if ((l & 6) == 4) break;
	}

	eligible = (l & 6) == 6;
     } while (!eligible);

    return true;
}

// NOTE: Efforts paid off
int main() {
    int totalSum = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
	std::vector<int> s;
	std::istringstream in(line);

	int i;
	while (in >> i) {
	    s.push_back(i);
	    in.ignore();
	}

	// Arrgh.  This is important
	sort(s.begin(), s.end());

	bool passed = true;

	int lhs = s[0], rhs = 0;
	for (int i = 1, j = s.size() - 1; i < j; ++i, --j) {
	    lhs += s[i];
	    rhs += s[j];
	    if (lhs <= rhs) {
		passed = false;
		break;
	    }
	}

	if (!passed) continue;

	std::vector<int> choose(s.size());
	reset(choose.begin(), choose.end());

	while (next(choose.begin(), choose.end())) {
	    int size1 = 0, size2 = 0;
	    int sum1 = 0, sum2 = 0;

	    for (int i = 0; i < choose.size(); ++i)
		if (choose[i] == 1) {
		    sum1 += s[i];
		    ++size1;
		}
		else if (choose[i] == 2) {
		    sum2 += s[i];
		    ++size2;
		}

	    if (size1 < size2 && sum1 >= sum2 ||
		size1 > size2 && sum1 <= sum2 ||
		size1 == size2 && sum1 == sum2) 
	    {
		passed = false;
		break;
	    }
	}

	if (!passed) continue;

	int sum = std::accumulate(s.begin(), s.end(), 0);
	totalSum += sum;
    }

    std::cout << totalSum << "\n";
    return 0;
}
