/******************************************************************************

                              Graphs.


*******************************************************************************/
// create an undireted graph --> find the adjacent matrix
// number of edges / vertices

#include <iostream>
using namespace std;

class Graph{
private:
    int v; // number of vertices
    int adjMatrix[10][10]; // fixed size adjacency matrix --> 10 rows | 10 columns
    
    
public:
    // constructor 
    Graph(int v){
        // stores numebr of passed vertices to the constructor
        // avoidng name conflict 
        this->v=v;

        for(int i=0; i<10; i++){
            for(int j=0; j<10;j++){
                adjMatrix[i][j]=0;
            }
        }
    }
    
    
    // Add undireted edge 
    void addEdge(int u , int w, bool directed=false){
        
        if (u>=0 && u<v  && w >=0 && w<v){
            
            adjMatrix[u][w]=1;
        
            if (! directed){
                adjMatrix[v][u]=1; // Adding reverse 
            }
        }else{
            
            cout << "Invlaide edge!" << endl;
        }
    }
    
    
    void printGraph(){
        
        cout << "The Matrix is :" << endl;
        
        for(int i=0; i<v; i++){
            for(int j=0; j<v; j++){
                cout <<  adjMatrix[i][j] <<"  " ;
            }
            cout << endl;
        }
    }
    
    
    
    
    
    
    
    
}; 






int main()
{   
    int vertice = 5;
    
    Graph object(vertice);
    object.addEdge(0,1); // edge between 0 and 1
    object.addEdge(0,2); // edge between 0 and 1
    object.addEdge(0,3); // edge between 0 and 1
    object.addEdge(0,4); // edge between 0 and 1
    
    object.addEdge(1,2); // edge between 0 and 1
    
    object.addEdge(3,3); // edge between 0 and 1
    
    object.printGraph();
    

}




