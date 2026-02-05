#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefix;
    
    // Constructor: builds the 2D prefix sum array
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefix.resize(rows + 1, vector<int>(cols + 1, 0));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                prefix[i+1][j+1] = prefix[i+1][j] + prefix[i][j+1] - prefix[i][j] + matrix[i][j];
            }
        }
    }
    
    // Returns sum of rectangle from (row1, col1) to (row2, col2)
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] + prefix[row1][col1];
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    NumMatrix nm(matrix);

    cout << "Sum of rectangle (0,0) to (1,1): " << nm.sumRegion(0, 0, 1, 1) << endl; // 1+2+4+5 = 12
    cout << "Sum of rectangle (1,1) to (2,2): " << nm.sumRegion(1, 1, 2, 2) << endl; // 5+6+8+9 = 28
    cout << "Sum of rectangle (0,0) to (2,2): " << nm.sumRegion(0, 0, 2, 2) << endl; // sum of all = 45

    return 0;
}
