#include <iostream>
#include <numeric>

const int DEPTH = 16;
const int N = 5;

void traverse(int depth, int config[N], double prob, int count, double& expectation) {
    if (depth == DEPTH && count) {
	expectation += prob * count;
	return;
    }

    int total = std::accumulate(config, config + N, 0);
    if (total == 1 && depth != 0 && depth != DEPTH - 1) ++count;

    for (int i = 0; i < N; ++i) 
	if (config[i]) {
	    double newProb = prob * config[i] / total;
	    --config[i];
	    for (int j = i + 1; j < N; ++j) ++config[j];

	    traverse(depth + 1, config, newProb, count, expectation);

	    ++config[i];
	    for (int j = i + 1; j < N; ++j) --config[j];
	}
}

int main() {
    int config[N] = { 1, 0, 0, 0, 0 };
    double expectation = 0.0;
    traverse(0, config, 1.0, 0, expectation);
    std::cout << expectation << "\n";
    return 0;
}
