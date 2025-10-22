#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY) return;

        // Union by rank
        if(rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if(rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};

int main() {
    DisjointSet ds(5); // 0 to 4

    ds.unite(0, 1);
    ds.unite(3, 4);

    cout << ds.find(1) << endl; // 0
    cout << ds.find(4) << endl; // 3

    ds.unite(1, 4);
    cout << ds.find(4) << endl; // 0

    return 0;
}

