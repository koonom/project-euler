#include <iostream>
#include <string>

using namespace std;

struct Hand {
    char values[5], suits[5];
    int hist[13], rank, subrank[5];

    istream& load(istream& in) {
	char v, s;
	for (int i = 0; i < 5; ++i)
	    if (in >> v >> s) {
		values[i] = v;
		suits[i] = s;
	    }
	    else break;

	fill_n(hist, 13, 0);
	for (int i = 0; i < 5; ++i)
	    if (values[i] >= '2' && values[i] <= '9') ++hist[values[i] - '2'];
	    else if (values[i] == 'T') ++hist[8];
	    else if (values[i] == 'J') ++hist[9];
	    else if (values[i] == 'Q') ++hist[10];
	    else if (values[i] == 'K') ++hist[11];
	    else if (values[i] == 'A') ++hist[12];

	int pattern = 1;
	for (int i = 0; i < 13; ++i)
	    if (hist[i])
		pattern *= hist[i] + 1;

	bool sameSuit = suits[0] == suits[1] && suits[1] == suits[2] && 
	    suits[2] == suits[3] && suits[3] == suits[4];

	int nn = 0;
	while (nn < 13 && hist[nn] == 0) ++nn;
	bool straight = nn <= 8 && 
	    hist[nn] * hist[nn + 1] * hist[nn + 2] * hist[nn + 3] * hist[nn + 4] == 1;

	if (straight && sameSuit) rank = 0; // Royal Flush and Straight Flush
	else if (pattern == 10) rank = 1; // Four of a kind
	else if (pattern == 12) rank = 2; // Full House
	else if (sameSuit) rank = 3; // Flush
	else if (straight) rank = 4; // Straight
	else if (pattern == 16) rank = 5; // Three of a Kind
	else if (pattern == 18) rank = 6; // Two Pairs
	else if (pattern == 24) rank = 7; // One Pair
	else if (pattern == 32) rank = 8; // High Card
	else exit(1);

	switch (rank) {
	case 0:
	case 3:
	case 4:
	case 8:
	    for (int m = 0, n = 12; n >= 0; --n)
		if (hist[n]) subrank[m++] = n;
	    break;
	case 1:
	    for (int n = 12; n >= 0; --n) 
		if (hist[n] == 4) subrank[0] = subrank[1] = subrank[2] = subrank[3] = n;
		else if (hist[n] == 1) subrank[4] = n;
	    break;
	case 2:
	    for (int n = 12; n >= 0; --n) 
		if (hist[n] == 3) subrank[0] = subrank[1] = subrank[2] = n;
		else if (hist[n] == 2) subrank[3] = subrank[4] = n;
	    break;
	case 5:
	    for (int m = 3, n = 12; n >= 0; --n)
		if (hist[n] == 3) subrank[0] = subrank[1] = subrank[2] = n;
		else if (hist[n] == 1) subrank[m++] = n;
	    break;
	case 6:
	    for (int m = 0, n = 12; n >= 0; --n) 
		if (hist[n] == 2) {
		    subrank[m] = subrank[m + 1] = n;
		    m += 2;
		}
		else if (hist[n] == 1) subrank[4] = n;
	    break;
	case 7:
	    for (int m = 2, n = 12; n >= 0; --n) 
		if (hist[n] == 2) subrank[0] = subrank[1] = n;
		else if (hist[n] == 1) subrank[m++] = n;
	    break;
	}

	return in;
    }

    bool isBetterThan(const Hand& opponent) {
	if (rank < opponent.rank) return true;
	else if (rank > opponent.rank) return false;

	for (int i = 0; i < 5; ++i) {
	    if (subrank[i] > opponent.subrank[i]) return true;
	    else if (subrank[i] < opponent.subrank[i]) return false;
	}

	exit(1);
    }
};

int main() {
    Hand player1, player2;
    int numberOfWins = 0;
    while (player1.load(cin) && player2.load(cin))
	if (player1.isBetterThan(player2)) ++numberOfWins;

    cout << numberOfWins << "\n";
    return 0;
}
