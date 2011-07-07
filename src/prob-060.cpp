#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <vector>
#include <gmpxx.h>
#include <boost/lexical_cast.hpp>

using namespace std;

const int K = 5;

typedef multimap<int, int> MapType;

void getPostings(MapType& g, int n, vector<int>& postings) {
    pair<MapType::iterator, MapType::iterator> p = g.equal_range(n);
    while (p.first != p.second) postings.push_back((p.first++)->second);
    // NOTE: need to sort the postings if using unordered_multimap
}

// I wonder if when was the last time I did branch-and-bound
int findClique(int k, MapType& g, vector<int>& vertices, vector<int>& clique, int upperBound) {
    if (vertices.size() < k) return 0;
    if (k == 1) return (vertices.front() > upperBound)? 0: vertices.front();

    if (accumulate(vertices.begin(), vertices.begin() + k - 1, 0) > upperBound)
	return 0;

    int lowestSum = 0;
    for (int i = k - 1; i < vertices.size(); ++i) {
	if (lowestSum && vertices[i] > lowestSum) break;

	vector<int> postings;
	getPostings(g, vertices[i], postings);

	vector<int> subset;
	set_intersection(vertices.begin(), vertices.begin() + i, 
	    postings.begin(), postings.end(), back_inserter(subset));

	int subSum = findClique(k - 1, g, subset, clique, upperBound - vertices[i]);

	if (subSum) {
	    if (!lowestSum || lowestSum > subSum + vertices[i])
		lowestSum = subSum + vertices[i];
	}
    }

    return lowestSum;
}

int findClique(int k, MapType& g, int n, vector<int>& clique, int upperBound) {
    if (g.count(n) < k - 1) return 0;

    vector<int> vertices;
    getPostings(g, n, vertices);

    int sum = findClique(k - 1, g, vertices, clique, upperBound - n);
    if (sum) return sum + n;
    else return 0;
}

const int N = 1000000;
bool composite[N + 1];

bool isComposite(const string& s) {
    if (s.size() > 6) {
	mpz_class n(s);
	return !mpz_probab_prime_p(n.get_mpz_t(), 5);
    }
    else return composite[boost::lexical_cast<int>(s)];
}

int main() {
    vector<int> primes;
    for (int n = 2; n <= N / 2; ++n)
	if (!composite[n]) {
	    for (int m = n + n; m <= N; m += n) composite[m] = true;
	    primes.push_back(n);
	}

    int lowestSum = N + 1;

    MapType g;
    vector<int>::const_iterator i, j;
    for (i = primes.begin(); i != primes.end(); ++i) {
	if (*i > lowestSum) break;
	string ii = boost::lexical_cast<string>(*i);
	for (j = primes.begin(); j != i; ++j) {
	    if (*i + *j > lowestSum) break;
	    string jj = boost::lexical_cast<string>(*j);

	    if (isComposite(ii + jj)) continue;
	    if (isComposite(jj + ii)) continue;
	    g.insert(MapType::value_type(*i, *j));
	}

	vector<int> clique;
	int sum = findClique(K, g, *i, clique, lowestSum);
	if (sum && lowestSum > sum) lowestSum = sum;
    }
    
    cout << lowestSum << "\n";
    return 0;
}
