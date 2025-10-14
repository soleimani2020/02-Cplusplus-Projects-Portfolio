/******************************************************************************

                              Online C++ Compiler.


*******************************************************************************/


#include <iostream>
#include <list>
#include <queue>
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
   
   
    // Add direted edge : one direction connection
    void addEdge(int u , int w){
       
        if (u>=0 && u<v  && w >=0 && w<v){
            adj[u].push_back(w);   // Adds w to the neighbor of u
        } else{
           
            cout << "Invalid edge!" << endl;
        }
       
    void BFS_TRAVERSE(int start_point){
       

        // q: queue of visited nodes
        bool visited_vertices[10]={false};
        queue <int> q;
        visited_vertices[start_point] = true;
        q.push(start_point);
       
        cout << "Starting vertice is:" << start_point << endl;
       
        while(!q.empty()){
           
            int node = q.front(); // first node  
            cout << node << "  ";
            q.pop(); // move to next node  
           
            for(int neighbor:adj[node]){
                if(!visited_vertices[neighbor])  // check if neighbor is not visited 
                {
                    visited_vertices[neighbor]=true; // mark it true if not 
                    q.push(neighbor)                 // push for later process
                }
            }
        }
       
        cout << endl;
    }
       
       
       
       

    }
   
   




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
   
    cout << "Determine starting point of traverse"<<endl;
    int start_point;
    cin>>start_point;
   
    object.BFS_TRAVERSE(start_point);


}




