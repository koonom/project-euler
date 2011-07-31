#include <algorithm>
#include <iostream>

const int N = 100000;
int rad[N + 1];
int seq[N + 1];

bool comp(int x, int y) {
    return rad[x] < rad[y] || rad[x] == rad[y] && x < y;
}

int main() {
    for (int n = 2; n <= N; ++n)
	if (!rad[n])
	    for (int m = n; m <= N; m += n)
		if (rad[m]) rad[m] *= n;
		else rad[m] = n;

    rad[1] = 1;

    for (int i = 1; i <= N; ++i) seq[i] = i;
    std::sort(seq + 1, seq + 1 + N, comp);
    std::cout << seq[10000] << "\n";
    return 0;
}
