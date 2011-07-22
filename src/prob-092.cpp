#include <iostream>
#include <vector>

const int N = 10000000;
int ends[N];

// NOTE: Any smart way to optimize?
int main() {
    int endsAt89 = 0;
    ends[1] = 1;
    ends[89] = 89;

    for (int n = 1; n < N; ++n) {
	if (ends[n]) {
	    endsAt89 += ends[n] == 89;
	    continue;
	}

	int m = n;
	do {
	    int sumOfSquares = 0;
	    for ( ; m; m /= 10) {
		int r = m % 10;
		sumOfSquares += r * r;
	    }
	    m = sumOfSquares;
	} while (!ends[m]);

	ends[n] = ends[m];
	endsAt89 += ends[n] == 89;
    }

    std::cout << endsAt89 << "\n";
    return 0;
}
