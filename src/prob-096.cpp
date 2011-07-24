#include <iostream>

using namespace std;

int sudoku[9][9];
int x[81], y[81], val[81], npoints;
int row[9], col[9], square[9];

void solve(int start) {
    if (start == npoints) {
	for (int k = 0; k < npoints; ++k)
	    sudoku[x[k]][y[k]] = val[k];
	//--------------------------------------------------
	// for (int i = 0; i < 9; ++i) {
	//     for (int j = 0; j < 9; ++j) cout << sudoku[i][j];
	//     cout << endl;
	// }
	// cout << endl;
	//-------------------------------------------------- 
	return;
    }

    int i = x[start];
    int j = y[start];

    for (int v = 1; v <= 9; ++v) {
	if (row[i] & (1 << v)) continue;
	if (col[j] & (1 << v)) continue;
	if (square[(i / 3) * 3 + j / 3] & (1 << v)) continue;

	val[start] = v;
	row[i] |= (1 << v);
	col[j] |= (1 << v);
	square[(i / 3) * 3 + j / 3] |= (1 << v);
	// sudoku[i][j] = v;

	solve(start + 1);

	val[start] = 0;
	row[i] &= ~(1 << v);
	col[j] &= ~(1 << v);
	square[(i / 3) * 3 + j / 3] &= ~(1 << v);
	// sudoku[i][j] = 0;
    }
}

int main() {
    string g; 
    int number, sum = 0;
    while (cin >> g >> number) {
	for (int i = 0; i < 9; ++i) row[i] = 0;
	for (int j = 0; j < 9; ++j) col[j] = 0;
	for (int k = 0; k < 9; ++k) square[k] = 0;
	npoints = 0;

	char c;
	for (int i = 0; i < 9; ++i)
	    for (int j = 0; j < 9; ++j) {
		cin >> c;
		int n = c - '0';
		sudoku[i][j] = n;

		if (n) {
		    row[i] |= (1 << n);
		    col[j] |= (1 << n);
		    square[(i / 3) * 3 + j / 3] |= (1 << n);
		}
		else {
		    x[npoints] = i;
		    y[npoints] = j;
		    val[npoints] = 0;
		    ++npoints;
		}

	    }
	solve(0);
	sum += sudoku[0][0] * 100 + sudoku[0][1] * 10 + sudoku[0][2];
    }

    cout << sum << "\n";
    return 0;
}
