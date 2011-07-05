#include <iostream>

const int N = 20; // assume words do not exceed 20 characters
bool triangle[26 * N + 1];

using namespace std;

bool isTriangleWord(string word) {
    int sum = 0;
    for (string::iterator i = word.begin(); i != word.end(); ++i)
	sum += *i - 'A' + 1;

    return triangle[sum];
}

int main() {
    for (int n = 1; n * (n + 1) <= 52 * N; ++n) triangle[n * (n + 1) / 2] = true;

    int numberOfTriangleWords = 0;

    string input;
    cin >> input;

    int first, second = -1;
    while (true) {
	if ((first = input.find('"', second + 1)) == string::npos) break;
	if ((second = input.find('"', first + 1)) == string::npos) break;
	string word = input.substr(first + 1, second - first - 1);
	if (isTriangleWord(word)) ++numberOfTriangleWords;
    }

    std::cout << numberOfTriangleWords << "\n";
    return 0;
}
