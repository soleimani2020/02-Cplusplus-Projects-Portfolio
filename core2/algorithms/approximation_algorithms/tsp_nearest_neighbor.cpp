/******************************************************************************

                              tsp_nearest_neighbor!


*******************************************************************************/

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TSP {
private:
    int n;  // number of cities
    vector<vector<int>> dist;
    vector<bool> visited;
    vector<int> path;
    int totalCost;

public:
    TSP(int cities) : n(cities), dist(cities, vector<int>(cities)), visited(cities, false), totalCost(0) {}

    void readDistances() {
        cout << "Enter distance matrix:\n";
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> dist[i][j];
    }

    void solveGreedy() {
        int current = 0;
        visited[current] = true;
        path.push_back(current);

        for (int step = 1; step < n; ++step) {
            int nextCity = -1;
            int minDist = numeric_limits<int>::max();

            for (int j = 0; j < n; ++j) {
                if (!visited[j] && dist[current][j] < minDist) {
                    minDist = dist[current][j];
                    nextCity = j;
                }
            }

            visited[nextCity] = true;
            totalCost += minDist;
            current = nextCity;
            path.push_back(current);
        }

        totalCost += dist[current][0];  // return to start
        path.push_back(0);
    }

    void printResult() const {
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << " -> ";
        }
        cout << "\nApproximate TSP cost: " << totalCost << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of cities: ";
    cin >> n;

    TSP tsp(n);
    tsp.readDistances();
    tsp.solveGreedy();
    tsp.printResult();

    return 0;
}

