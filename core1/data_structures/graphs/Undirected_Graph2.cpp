/******************************************************************************

                              Graphs.


*******************************************************************************/
// Adjacency Listfor undireted graph 
// number of edges / vertices

#include <iostream>
#include <list> 
using namespace std;

class Graph{
private:
    int v; // number of vertices
    list <int> adj[10]; // Array of lists 
    
    
public:
    // constructor 
    Graph(int v){
        // stores numebr of passed vertices to the constructor
        // avoidng name conflict 
        this->v=v;
    }
    
    
    // Add undireted edge 
    void addEdge(int u , int w){
        
        if (u>=0 && u<v  && w >=0 && w<v){
            adj[u].push_back(w);   // Adds w to the neighbor of u
            adj[w].push_back(u);   // Adds u to the neighbor of w
        } else{
            
            cout << "Invalid edge!" << endl;
        }

    }
    
    
    void printGraph(){
        
        cout << "The Adjacency List:" << endl;
        
        for(int i=0; i<v; i++){
            cout << i << " --> " ;   // 
            for(int neighbour:adj[i]){
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
    
}; 






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
    object.printGraph();
    

}





