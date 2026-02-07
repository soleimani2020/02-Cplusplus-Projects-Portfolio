#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        // grid[i][j]==0 >>> Water 
        // grid[i][j]==1 >>> Land
        
        int total = 0;
        
        int rows  = grid.size();
        int cols = grid[0].size();
        

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if (grid[i][j]==1){      // Land 
                    int perimeter = 4;  // default perimeter
                    // Up
                    if (i > 0 && grid[i-1][j] == 1) perimeter--;
                    // Down
                    if (i < rows - 1 && grid[i+1][j] == 1) perimeter--;
                    // Left 
                    if (j > 0 && grid[i][j-1] == 1) perimeter--;
                    // Right 
                    if (j < cols - 1 && grid[i][j+1] == 1) perimeter--;
                    
                    total+=perimeter;
                }
            }
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
    int perimeter = sol.islandPerimeter(grid);

    cout << "Island Perimeter: " << perimeter << endl;

    return 0;
}




