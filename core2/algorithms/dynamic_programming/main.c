/*******************************************************************************
 *
 *                              Knapsack
 *
 *  Description:
 *  ------------
 *  Solves the 0/1 Knapsack problem using Dynamic Programming (bottom-up method).
 *  Given a set of items, each with a weight and value, the algorithm determines
 *  the maximum total value that can be carried within a fixed capacity.
 *
 *******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Knapsack {
private:
    int capacity;                      // Maximum allowed weight
    vector<int> weights;               // Weights of items
    vector<int> values;                // Values of items
    vector<vector<int>> dp;            // DP table

public:
    // Constructor
    Knapsack(int W, const vector<int>& w, const vector<int>& v)
        : capacity(W), weights(w), values(v) {
        dp.resize(weights.size() + 1, vector<int>(capacity + 1, 0));
    }

    // Solve the problem using bottom-up dynamic programming
    int solve() {
        int n = weights.size();
        for (int i = 1; i <= n; ++i) {
            for (int w = 1; w <= capacity; ++w) {
                if (weights[i - 1] <= w) {
                    dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]],
                                   dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][capacity];
    }

    // Display the DP table
    void printDPTable() const {
        cout << "\nDP Table:\n";
        for (const auto& row : dp) {
            for (int val : row) {
                cout << val << "\t";
            }
            cout << endl;
        }
    }
};

int main() {

    vector<int> values  = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    // Create and solve the Knapsack problem
    Knapsack ks(capacity, weights, values);
    int maxValue = ks.solve();

    cout << "Maximum value in the knapsack = " << maxValue << endl;
    ks.printDPTable();

    return 0;
}
