#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <gmpxx.h>

int main() {
    using namespace std;

    unordered_map<string, int> numberOfCubes;
    unordered_map<string, string> lowestPermutation;

    for (int i = 1; ; ++i) {
	mpz_class cube;
	mpz_ui_pow_ui(cube.get_mpz_t(), i, 3);

	// string number = boost::lexical_cast<string>(cube);
	string number = cube.get_str();
	string permuted = number;
	sort(permuted.begin(), permuted.end());

	++numberOfCubes[permuted];
	if (lowestPermutation.find(permuted) == lowestPermutation.end())
	    lowestPermutation.insert(make_pair(permuted, number)); 

	if (numberOfCubes[permuted] == 5) {
	    cout << lowestPermutation[permuted] << "\n";
	    return 0;
	}
    }

    return 0;
}
