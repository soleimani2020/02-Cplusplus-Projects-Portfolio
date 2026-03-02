#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c){
        int m = mat.size();
        int n = mat[0].size();
        
        if(m * n != r * c)
            return mat;
        
        vector<int> flat;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                flat.push_back(mat[i][j]);
            }
        }
        
        
        
        vector<vector<int>> newMat(r, vector<int>(c));
        int k = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                newMat[i][j] = flat[k++];
            }
        }
        
        return newMat;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}};
    int r = 3, c = 2;
    
    vector<vector<int>> reshaped = sol.matrixReshape(mat, r, c);
    
    // Print the reshaped matrix
    for(int i = 0; i < reshaped.size(); i++){
        for(int j = 0; j < reshaped[0].size(); j++){
            cout << reshaped[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
