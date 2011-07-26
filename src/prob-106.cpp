#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <sstream>

//--------------------------------------------------
// Shameless copy (again) from Problem 103
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

const int N = 12;
int choose[N];

int main() {
    int numberOfEqualities = 0;

    reset(choose, choose + N);
    while (next(choose, choose + N)) {
	int n1 = 0, n2 = 0;
	for (int i = 0; i < N; ++i)
	    if (choose[i] == 1) ++n1;
	    else if (choose[i] == 2) ++n2;

	if (n1 != n2) continue;

	int i1 = -1, i2 = -1; // HACK

	do {
	    ++i1;
	    ++i2;
	    while (i1 != N && choose[i1] != 1) ++i1;
	    while (i2 != N && choose[i2] != 2) ++i2;
	} while (i1 < i2);

	if (i1 == N && i2 == N) continue;

	++numberOfEqualities;

	//--------------------------------------------------
	// std::copy(choose, choose + N, std::ostream_iterator<int>(std::cout, " "));
	// std::cout << std::endl;
	//-------------------------------------------------- 
    }

    std::cout << numberOfEqualities << "\n";
    return 0;
}
