/******************************************************************************

                              BFS

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class GRAPH{
    
public:
    int V;
    vector<vector<int>> adj;
    
    GRAPH(int vertices){
        V = vertices;
        adj.resize(V);
    }
    
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    
    
    void BFS(int start){
        
        queue<int> q;
        vector<bool> visited(V, false);
        
        
        visited[start]=true;
        q.push(start);
        
        while( !q.empty() ){
            
            int node = q.front();
            q.pop();
            cout << node << " " << endl;
            
            for(int i=0; i<adj[node].size() ;i++){
                int neighbor = adj[node][i];
                if (!visited[neighbor]){
                    visited[neighbor]=true;
                    q.push(neighbor);
                }
            }
            
        }
  
    }
    
    
    
}; // end 

int main() {
    GRAPH g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from node 0: ";
    g.BFS(0);

    return 0;
}
