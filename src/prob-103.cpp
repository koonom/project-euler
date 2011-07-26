#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <sstream>

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

const int N = 7;
int s[N];
int choose[N];

int recurse(int index, int minimum, int maximum, std::string& result) {
    if (index == N - 1) {
	s[index] = maximum;

	int lhs = s[0], rhs = 0;
	for (int i = 1, j = N - 1; i < j; ++i, --j) {
	    lhs += s[i];
	    rhs += s[j];
	    if (lhs <= rhs) return 0;
	}

	reset(choose, choose + N);
	while (next(choose, choose + N)) {
	    int size1 = 0, size2 = 0;
	    int sum1 = 0, sum2 = 0;

	    for (int i = 0; i < N; ++i)
		if (choose[i] == 1) {
		    sum1 += s[i];
		    ++size1;
		}
		else if (choose[i] == 2) {
		    sum2 += s[i];
		    ++size2;
		}

	    if (size1 < size2 && sum1 >= sum2) 
		return 0;
	    else if (size1 > size2 && sum1 <= sum2) 
		return 0;
	    else if (size1 == size2 && sum1 == sum2) 
		return 0;
	}

	std::ostringstream out;
	std::copy(s, s + N, std::ostream_iterator<int>(out, ""));
	result = out.str();

	int sum = std::accumulate(s, s + N, 0);
	return sum;
    }

    for (int i = minimum; i < maximum; ++i) {
	s[index] = i;
	int sum = recurse(index + 1, i + 1, maximum, result);
	if (sum > 0) return sum;
    }

    return 0;
}

// NOTE: This problem is so cool
int main() {
    std::string result;
    int m = N;
    while (recurse(0, 1, m, result) <= 0) ++m;

    std::cout << result << "\n";
    return 0;
}
