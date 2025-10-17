/******************************************************************************
Flood fill algorithm C++ ! 

/*
🧠 Flood Fill Using Depth-First Search (DFS)

🚀 Algorithm Summary:

🔹 Start from a given cell (x, y) in the grid
🔸 Check if the cell matches the target color/value
🔹 If it does, replace it with the new color
🔸 Recursively explore in 4 directions:
    ↪ Up (x - 1, y)
    ↪ Right (x, y + 1)
    ↪ Down (x + 1, y)
    ↪ Left (x, y - 1)
🔹 Follows Depth-First Search (DFS): explores deeply before backtracking
🔸 Skip cells that are:
    ⛔ Out of bounds
    ⛔ Already filled
    ⛔ Not matching the target color
🔹 Stops when all connected matching cells are filled
*/




#include <iostream>
using namespace std;

const int rows = 3;
const int cols = 3;





class FloodFill{
private:


    void Fill_helper(int x, int y, int target_color, int replacement_color,int grid[rows][cols]){


        // Prevents going outside the grid (boundary condition).
        if (x < 0 || x >= rows || y < 0 || y >= cols)
            return;
        
        // If the current cell is not the target color, or it is already filled with the replacement color, stop!
        
        if (grid[x][y] != target_color || grid[x][y] == replacement_color)
            return;
            

        // Replace the color.
        grid[x][y]= replacement_color;
        
        // dx= {-1,0,+1, 0};
        // dy= {0 ,1,0 ,-1};
        // Depth-First Search (DFS).
        // Recursively explores the four connected neighbors (DFS).
        
        Fill_helper(x - 1, y, target_color, replacement_color, grid);
        Fill_helper(x, y + 1, target_color, replacement_color, grid);
        Fill_helper(x + 1, y, target_color, replacement_color, grid);
        Fill_helper(x, y - 1, target_color, replacement_color, grid);
        
   
    }



public:

    void Fill(int x, int y, int replacement_color, int grid[rows][cols]){
        
        if (x < 0 || x >= rows || y < 0 || y >= cols)
            return;
        
        int target_color = grid[x][y];


        // Calls the helper only if the target color is different from the replacement color (avoids infinite recursion).
        if (target_color != replacement_color){
            Fill_helper(x,y,target_color,replacement_color,grid);
        }
        
    }
    
    
    void display(int grid[rows][cols]){
        for (int i=0; i < rows; i++){
            for(int j=0; j< cols; j++){
                cout << grid[i][j] << "  " ;
            }
            
            cout << endl;
        }
    }


    
}; // End of class 



int main() {
    
    FloodFill object;
    
    
    int grid[3][3] ={
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    
    
    cout << "Original grid:"<< endl;
    object.display(grid);

    // Starts flood fill at position (0,0) and Replacement color = 3.
    object.Fill(0,0,3,grid);
    
    cout << "Grif after Flood Fill implemented:"<< endl;
    object.display(grid);


    return 0;
}
