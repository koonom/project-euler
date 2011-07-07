#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
    using namespace std;
    
    int code;
    string cipher;

    while (cin >> code) { 
	cipher.push_back(char(code));
	cin.ignore();
    }

    char key[3];
    int maxKeyCode = 26 * 26 * 26;
    for (int i = 0; i < maxKeyCode; ++i) {
	for (int j = 0, m = i; j < 3; ++j, m /= 26) key[j] = 'a' + m % 26;

	string text;
	bool bad = false;
	for (int j = 0; j < cipher.size(); ++j) {
	    char c = cipher[j] ^ key[j % 3];
	    text.push_back(c);
	    if (!isprint(c)) {
		bad = true;
		break;
	    }
	}

	if (bad) continue;
	if (text.find(" the ") == string::npos) continue;

	int sum = 0;
	for (int j = 0; j < text.size(); ++j) sum += text[j];
	std::cout << sum << "\n";
	return 0;
    }

    return 0;
}
