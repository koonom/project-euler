#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

const int N = 1000000000;

int main() {
    // prepare square numbers
    vector<int> squares[10];
    unordered_set<int> allSquares;
    int sqrtN = sqrt(N);
    for (int i = 1; i <= sqrtN; ++i) {
	int s = i * i;
	allSquares.insert(s);

	int order = 0;
	for (int m = s; m; m /= 10) ++order;
	squares[order].push_back(s);
    }

    // prepare word pairs
    string input;
    cin >> input;

    vector<string> words, sigs;
    int pos = 0; 

    while ((pos = input.find('"', pos)) != string::npos) {
	int pos2 = input.find('"', pos + 1);
	string word = input.substr(pos + 1, pos2 - pos - 1);
	pos = pos2 + 1;

	words.push_back(word);
	sigs.push_back(word);
	sort(sigs.back().begin(), sigs.back().end());
    }

    int largestSquareAnagram = 0;

    // run
    for (int i = 0; i < words.size(); ++i) 
	for (int j = i + 1; j < words.size(); ++j) {
	    if (sigs[i] != sigs[j] || 
		equal(words[i].begin(), words[i].end(), words[j].rbegin())) continue;

	    int letterToDigit[26], digitToLetter[10]; // store number in reverse
	    int ndigits = words[i].size();

	    for (int k = 0; k < squares[ndigits].size(); ++k) {
		bool failed = false;
		int n = squares[ndigits][k];
		fill_n(letterToDigit, 26, -1);
		fill_n(digitToLetter, 10, -1);

		for (int m = n, l = ndigits - 1; m; m /= 10, --l) {
		    char c = words[i][l];
		    int d = m % 10;

		    if (letterToDigit[c - 'A'] >= 0 || digitToLetter[d] >= 0) {
			failed = true;
			break;
		    }

		    letterToDigit[c - 'A'] = d;
		    digitToLetter[d] = c - 'A';
		}

		if (failed) continue;
		if (letterToDigit[words[j][0] - 'A'] == 0) continue;

		int nn = 0;
		for (int l = 0; l < words[j].size(); ++l)
		    nn = 10 * nn + letterToDigit[words[j][l] - 'A'];

		if (allSquares.find(nn) != allSquares.end()) {
		    int candidate = max(n, nn);
		    if (candidate > largestSquareAnagram) 
			largestSquareAnagram = candidate;
		}
	    }
	}

    cout << largestSquareAnagram << "\n";
    return 0;
}
