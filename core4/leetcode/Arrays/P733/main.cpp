#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        int rows = image.size();
        int cols = image[0].size();
        
        // Base Case 
        if (image[sr][sc] == color){
            return image; // Do Nothing 
        }
            
            
        int originalColor = image[sr][sc];
        
        image[sr][sc] = color;
        
        // Up
        if(sr>0 && image[sr-1][sc]==originalColor)
            floodFill(image, sr-1, sc, color);
            
        // Down
        if(sr<rows-1 && image[sr+1][sc]==originalColor)
            floodFill(image, sr+1, sc, color);
            
        // Left
        if(sc>0 && image[sr][sc-1]==originalColor)
            floodFill(image, sr, sc-1, color);
            
        // Right
        if(sc<cols-1 && image[sr][sc+1]==originalColor)
            floodFill(image, sr, sc+1, color);  
            
        
        return image;
  
    }
};

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1, sc = 1, newColor = 2;

    Solution sol;
    vector<vector<int>> res = sol.floodFill(image, sr, sc, newColor);

    cout << "Flood Filled Image:\n";
    for (auto row : res) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}


