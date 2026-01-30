#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to generate Pascal's Triangle with numRows rows
    vector<vector<int>> generate(int numRows) 
    {
        // This will store the entire triangle
        vector<vector<int>> result;
        
        // If no rows are requested, return an empty result
        if (numRows == 0) return result;
        
        // First row is always [1]
        vector<int> first_row;
        first_row.push_back(1);
        result.push_back(first_row);
        
        // If only one row is requested, return immediately
        if (numRows == 1) return result;
        
        // Generate rows 2 to numRows
        for (int i = 1; i < numRows; i++) {
            
            // Get the previous row
            vector<int> prev_row = result[i - 1];
            
            // Start the current row with 1
            vector<int> curr_row;
            curr_row.push_back(1);
            
            // Compute the middle elements of the current row
            // Each value is the sum of the two values above it
            for (int j = 0; j < i - 1; j++) {
                curr_row.push_back(prev_row[j] + prev_row[j + 1]);
            }
            
            // End the current row with 1
            curr_row.push_back(1);
            
            // Add the current row to the result
            result.push_back(curr_row);
        }
        
        // Return the full Pascal's Triangle
        return result;
    }
};

int main() {
    
    Solution object;
    
    int numRows = 5;
    
    // Generate Pascal's Triangle
    vector<vector<int>> triangle = object.generate(numRows);
    
    // Print the triangle row by row
    for (auto row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
