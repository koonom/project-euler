#include <iostream>
#include <gmpxx.h>

const int N = 500500;
int s[N], row[N];

// NOTE: Runs in 4.5 seconds.  Can it be improved?
int main() {
    mpz_class t = 0, LIMIT = 1 << 20;
    for (int k = 1; k <= N; ++k) {
	t = (615949 * t + 797807) % LIMIT;
	s[k - 1] = t.get_si() - (1 << 19);
    }

    for (int n = 0, m = 1; n < N; ++m) 
	for (int i = 0; i < m; ++i) row[n++] = m;

    int globallyBest = 0;

    for (int ub = N - 1; ub >= 0; ub -= row[ub]) {
	int treeSum[N];
	int best = s[ub];

	for (int j = ub; j >= 0; --j) {
	    treeSum[j] = s[j];

	    int child = j + row[j];
	    if (child <= ub) {
		treeSum[j] += treeSum[child] + treeSum[child + 1];

		int grandChild = child + row[child] + 1;
		if (grandChild <= ub) treeSum[j] -= treeSum[grandChild];
	    }

	    if (treeSum[j] < best) best = treeSum[j];
	}

	if (best < globallyBest) globallyBest = best;
    }

    std::cout << globallyBest << "\n";
}
