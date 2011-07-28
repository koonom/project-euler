#include <cmath>
#include <iostream>
#include <gmpxx.h>

//--------------------------------------------------
// Turner, L. Richard. Inverse of the Vandermonde matrix with applications
// http://ntrs.nasa.gov/archive/nasa/casi.ntrs.nasa.gov/19660023042_1966023042.pdf
//-------------------------------------------------- 
class InverseVandermondeMatrix {
    // A simple implmentation for Stirling numbers Of the first kind
    static mpz_class stirlingNumber1(int n, int k) {
	if (n == 0 && k == 0) return 1;
	if (n == 0 || k == 0) return 0;

	mpz_class s;
	s = stirlingNumber1(n - 1, k);
	s *= n - 1;
	s += stirlingNumber1(n - 1, k - 1);
	return s;
    }

    static mpz_class factorial(int n) {
	mpz_class f;
	mpz_fac_ui(f.get_mpz_t(), n);
	return f;
    }

    int ndims;

public:
    InverseVandermondeMatrix(int n): ndims(n) {}

    mpz_class getInverseU(int i, int j) {
	mpz_class element = stirlingNumber1(j, i);
	return (i + j) & 1? -1 * element: element;
    }

    mpq_class getInverseL(int i, int j) {
	if (i < j) return 0;
	mpz_class denom = factorial(j - 1);
	denom *= factorial(i - j);
	return mpq_class((i + j) & 1? -1: 1, denom);
    }

    mpq_class get(int i, int j) {
	mpq_class sum = 0;
	for (int k = 1; k <= ndims; ++k)
	    sum += getInverseU(i, k) * getInverseL(k, j);
	return sum;
    }

    // Compute a^T V^{-1} b
    template<typename Iterator>
    mpq_class compute(Iterator first1, Iterator first2)
    {
	mpq_class result = 0;
	for (int i = 0; i < ndims; ++i) {
	    mpq_class partial = 0;
	    for (int j = 0; j < ndims; ++j)
		partial += get(i + 1, j + 1) * *(first2 + j);
	    result += *(first1 + i) * partial;
	}
	return result;
    }
};

int response(int n) {
    // return n * n * n;
    int sum = 0;
    for (int i = 0; i <= 10; ++i) {
	int sgn = (i & 1)? -1: 1;
	sum += sgn * std::pow(n, i);
    }

    return sum;
}

int predictor(int x, int n) {
    if (n == 1) return 1;
    else if (n == 2) return x;
    else if (n == 3) return x * x; 
    else if (n == 4) return x * x * x;
    else return std::pow(x, n - 1);
}

const int N = 10;

int main() {
    mpz_class predictors[N], response[N + 1], sum = 0;

    for (int k = 0; k <= N; ++k) {
	response[k] = 0;
	for (int x = k + 1, l = 0; l <= 10; ++l) { 
		mpz_class xToL;
		mpz_ui_pow_ui(xToL.get_mpz_t(), x, l);
		if (l & 1) xToL *= -1;
		response[k] += xToL;
	}
    }

    for (int n = 1; n <= N; ++n) {
	InverseVandermondeMatrix v(n);

	predictors[0] = 1;
	for (int k = 1; k < n; ++k)
	    predictors[k] = predictors[k - 1] * (n + 1);

	mpz_class guess = v.compute(predictors, response);
	if (guess != response[n]) sum += guess;
    }

    std::cout << sum << "\n";
    return 0;
}
