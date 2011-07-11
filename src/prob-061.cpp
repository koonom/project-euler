#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>

using namespace std;

const int N = 10000;
int polygonals[N + 1]; 

int triangle(int n) { return n * (n + 1) / 2; }
int square(int n) { return n * n; }
int pentagonal(int n) { return n * (3 * n - 1) / 2; }
int hexagonal(int n) { return n * (2 * n - 1); }
int heptagonal(int n) { return n * (5 * n - 3) / 2; }
int octagonal(int n) { return n * (3 * n - 2); }

void compute(vector<int>& picks) {
    if (picks.size() == 6) {
	if (picks.front() / 100 != picks.back() % 100) return;

	int mask = 0;
	for (int i = 0; i < picks.size(); ++i) mask |= polygonals[picks[i]];

	if (mask != (1 << 6) - 1) return;

	vector<int> s;
	for (int i = 0; i < picks.size(); ++i) s.push_back(polygonals[picks[i]]);
	sort(s.begin(), s.end());

	bool good = false;

	do {
	    if ((s[0] & 1) && (s[1] & 2) && (s[2] & 4) && (s[3] & 8) &&
		(s[4] & 16) && (s[5] & 32)) 
	    {
		good = true;
		break;
	    }
	} while (next_permutation(s.begin(), s.end()));

	if (good) {
	    cout << accumulate(picks.begin(), picks.end(), 0) << "\n";
	}

	return;
    }

    vector<int> candidates;

    if (picks.empty()) {
	for (int n = 1000; n < N; ++n) 
	    if (polygonals[n] && n % 100 >= 10) candidates.push_back(n);
    }
    else {
	int start = (picks.back() % 100) * 100 + 10;
	int end = start + 90;

	for (int n = start; n < end; ++n) {
	    if (n <= picks.front()) continue;
	    if (polygonals[n]) candidates.push_back(n);
	}
    }

    for (vector<int>::iterator ii = candidates.begin();
	 ii != candidates.end(); ++ii)
    {
	picks.push_back(*ii);
	compute(picks);
	picks.pop_back();
    }
}

int main() {
    for (int n = 1; triangle(n) < N; ++n) polygonals[triangle(n)] += 1;
    for (int n = 1; square(n) < N; ++n) polygonals[square(n)] += 2;
    for (int n = 1; pentagonal(n) < N; ++n) polygonals[pentagonal(n)] += 4;
    for (int n = 1; hexagonal(n) < N; ++n) polygonals[hexagonal(n)] += 8;
    for (int n = 1; heptagonal(n) < N; ++n) polygonals[heptagonal(n)] += 16;
    for (int n = 1; octagonal(n) < N; ++n) polygonals[octagonal(n)] += 32;

    vector<int> picks;
    compute(picks);
    return 0;
}
