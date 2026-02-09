#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid, vector<int>& start) {
        
        queue<pair<int,int>> q; // i , j
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        int r = start[0];
        int c = start[1];
        
        q.push({r,c});
        visited[r][c] = true;
        
        int total = 0;
        
        while(!q.empty()){
            
            pair<int,int> cell = q.front();
            q.pop();
            
            int i = cell.first;   // row 
            int j = cell.second;  // col
            
            int cell_perimeter = 4;
            
            // directions: up, down, left, right
            vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
            
            for(auto dir: directions){
                
                int ni = i + dir.first;
                int nj = j + dir.second;
                
                // neighbor out of bounds?
                if(ni < 0 || ni >= rows || nj < 0 || nj >= cols)
                    continue;
                
                // neighbor is water
                if(grid[ni][nj] == 0)
                    continue;
                
                // neighbor is land
                if(grid[ni][nj] == 1 && !visited[ni][nj]){
                    cell_perimeter--;           // shared edge
                    visited[ni][nj] = true;
                    q.push({ni,nj});           // visit later
                }
                else if(grid[ni][nj] == 1 && visited[ni][nj]){
                    cell_perimeter--;           // shared edge with visited land
                }
            }
            
            total += cell_perimeter; // add perimeter of this cell
        }
        
        return total;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    Solution sol;
    
    vector<int> start = {0, 1};
    
    int perimeter = sol.islandPerimeter(grid, start);

    cout << "Island Perimeter: " << perimeter << endl;

    return 0;
}

