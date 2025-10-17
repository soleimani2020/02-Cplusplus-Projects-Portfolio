/******************************************************************************

                              DFS Graph Traversal.

# We use STACK (LIFO)

*******************************************************************************/

#include <iostream>
#include <list>
using namespace std;

class Graph{
private:
    int v; // number of vertices
    list <int> adj[10]; // fixed-size array of adjanency lists 
    
public:
    Graph(int v){
        this->v = v;
    }
    
    
    void addEdge(int u, int w){
        if ( u >= 0 && u<v && w >= 0 && w < v){
            adj[u].push_back(w);  // add w to u's adjanency list 
            adj[w].push_back(u);  // add u to w's adjanency list
        }else{ 
            cout << "Ihttps://www.onlinegdb.com/online_c++_compiler#tab-stdinnvallid edge!" << endl;
        }
    }
    
    

    
    
    void DFS_traversal(int start, bool Visited[]){
        
        // initially: Visited = [false,false,false,..]
        // make the start node as visited
        Visited[start]=true;
        
        cout << "Node:" << start << endl;
        
        // recursively look for the next node
        for(int neighbor:adj[start]){
            if (!Visited[neighbor]){
                DFS_traversal(neighbor,Visited);
            }
        }
  
    }
    

    
}; //Class End


int main()
{


    int vertice = 5;
    // Graph edges: (0,1) ,(0,2), (0,3), (0,4) , (1,2). (3,3)
    Graph object(vertice);
    object.addEdge(0,1); // edge between 0 and 1
    object.addEdge(0,2); // edge between 0 and 1
    object.addEdge(0,3); // edge between 0 and 1
    object.addEdge(0,4); // edge between 0 and 1
    object.addEdge(1,2); // edge between 0 and 1
    object.addEdge(3,3); // edge between 0 and 1
    
    cout << "Graph traversal using DFS:" << endl;
    
    bool Visited[10] = {false};
    
    object.DFS_traversal(0,Visited);
    
    return 0;








}
