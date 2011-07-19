#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <boost/format.hpp>

using namespace std;

//--------------------------------------------------
// Utility
//-------------------------------------------------- 
template<typename Pair, typename Predicate>
struct Choose2nd {
    Predicate pred;

    bool operator()(const Pair& x, const Pair& y) {
        return pred(x.second, y.second);
    }
};

template<typename Pair, typename Predicate>
Choose2nd<Pair, Predicate> choose2nd(Predicate pred) {
    return Choose2nd<Pair, Predicate>();
}

//--------------------------------------------------
// Main program
//-------------------------------------------------- 
string labels[40] = {
    "GO", "A1", "CC1", "A2", "T1", "R1", "B1", "CH1", "B2", "B3", 
    "JAIL", "C1", "U1", "C2", "C3", "R2", "D1", "CC2", "D2", "D3", 
    "FP", "E1", "CH2", "E2", "E3", "R3", "F1", "F2", "U2", "F3",
    "G2J", "G1", "G2", "CC3", "G3", "R4", "CH3", "H1", "T2", "H2"
};

const int FACE = 4;
const double EPSILON = 0.0000001;

double pDice[2 * FACE + 1];
bool isDouble[2 * FACE + 1];

int main() {
    for (int i = 1; i <= FACE; ++i)
	for (int j = 1; j <= FACE; ++j) ++pDice[i + j];

    for (int i = 2; i <= 2 * FACE; ++i) pDice[i] /= FACE * FACE;
    for (int i = 1; i <= FACE; ++i) isDouble[i + i] = true;
	
    double p[40];
    for (int i = 0; i < 40; ++i) p[i] = 1.0 / 40;

    while (true) {
	double pp[40];
	for (int i = 0; i < 40; ++i) pp[i] = 0;

	for (int i = 0; i < 40; ++i) {
	    for (int j = 2; j <= 2 * FACE; ++j) {
		int l = (i + j) % 40;
		double pLanding = p[i] * pDice[j];

		if (labels[l] == "CC1" || labels[l] == "CC2" || labels[l] == "CC3") {
		    pp[0] += pLanding / 16; // GO
		    pp[10] += pLanding / 16; // JAIL
		    pp[l] += pLanding * 14 / 16; // Stay
		}
		else if (labels[l] == "CH1" || labels[l] == "CH2" || labels[l] == "CH3") {
		    pp[0] += pLanding / 16; // GO
		    pp[10] += pLanding / 16; // JAIL
		    pp[11] += pLanding / 16; // C1
		    pp[24] += pLanding / 16; // E3
		    pp[39] += pLanding / 16; // H2
		    pp[5] += pLanding / 16; // R1

		    int rr = (l + 1) % 40; 
		    while (labels[rr] != "R1" && labels[rr] != "R2" &&
			   labels[rr] != "R3" && labels[rr] != "R4") rr = (rr + 1) % 40;

		    pp[rr] += pLanding * 2 / 16; // next R

		    int uu = (l + 1) % 40; 
		    while (labels[uu] != "U1" && labels[uu] != "U2") uu = (uu + 1) % 40;

		    pp[uu] += pLanding / 16; // next U

		    pp[(l - 3) % 40] += pLanding / 16; // Go back 3 squares
		    pp[l] += pLanding * 6 / 16; // Stay
		}
		else if (labels[l] == "G2J") {
		    pp[10] += pLanding;
		}
		else {
		    pp[l] += pLanding;
		}
	    }
	}

	double err = 0;
	for (int i = 0; i < 40; ++i) err += std::fabs(p[i] - pp[i]);

	if (err < EPSILON) break;

	for (int i = 0; i < 40; ++i) p[i] = pp[i];
    }

    vector< pair<string, double> > seq;

    for (int i = 0; i < 40; ++i) 
	seq.push_back(make_pair(str(boost::format("%02d") % i), p[i]));

    sort(seq.begin(), seq.end(), choose2nd< pair<string, double> >(std::greater<double>()));
    std::cout << seq[0].first << seq[1].first << seq[2].first << "\n";
    return 0;
}
