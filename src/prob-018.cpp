#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

int main() {
    using namespace std;

    string input =
	"75 "
	"95 64 "
	"17 47 82 "
	"18 35 87 10 "
	"20 04 82 47 65 "
	"19 01 23 75 03 34 "
	"88 02 77 73 07 63 67 "
	"99 65 04 28 06 16 70 92 "
	"41 41 26 56 83 40 80 70 33 "
	"41 48 72 33 47 32 37 16 94 29 "
	"53 71 44 65 25 43 91 52 97 51 14 "
	"70 11 33 28 77 73 17 78 39 68 17 57 "
	"91 71 52 38 17 14 91 43 58 50 27 29 48 "
	"63 66 04 68 89 53 67 30 73 16 69 87 40 31 "
	"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23 ";

    vector<int> numbers;
    vector<int> levels;

    istringstream in(input);
    copy(istream_iterator<int>(in), istream_iterator<int>(),
	 back_inserter(numbers));

    int level = 0;

    // I don't care if they don't match
    while (levels.size() < numbers.size()) {
	++level;
	for (int i = 0; i < level; ++i) levels.push_back(level);
    }

    int N = numbers.size();
    for (int i = N - 1; i >= 0; --i) {
	if (i + levels[i] >= N) continue;

	int left = numbers[i + levels[i]], right = numbers[i + levels[i] + 1];
	numbers[i] += (left > right)? left: right;
    }

    cout << numbers[0] << "\n";
    return 0;
}
