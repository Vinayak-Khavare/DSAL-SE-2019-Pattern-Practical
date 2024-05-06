#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to calculate optimal binary search tree cost
float optimalBSTCost(const vector<float>& probabilities, int n) {
    // Create a 2D table to store minimum costs
    vector<vector<float>> cost(n + 1, vector<float>(n + 1, 0));

    // Base case: cost is equal to the probability for a single node
    for (int i = 0; i < n; ++i)
        cost[i][i] = probabilities[i];

    // Fill the table diagonally
    for (int L = 2; L <= n; ++L) {
        for (int i = 0; i <= n - L + 1; ++i) {
            int j = i + L - 1;
            cost[i][j] = numeric_limits<float>::max();

            // Try making all keys in interval [i, j] as root
            for (int r = i; r <= j; ++r) {
                // Calculate cost when r is root of subtree
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          probabilities[r];
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }
    return cost[0][n - 1];
}

int main() {
    vector<float> probabilities = {0.1, 0.2, 0.4, 0.3}; // Example probabilities
    int n = probabilities.size();
    float minCost = optimalBSTCost(probabilities, n);

    cout << "The minimum search cost of the optimal BST is: " << minCost << endl;

    return 0;
}
