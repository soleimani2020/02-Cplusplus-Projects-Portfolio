/******************************************************************************
                                N-QUEENS PROBLEM 

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NQueens{
    
private:

    int N; // Board size 
    vector<int> board;  // dynamic vector : board[2]=3 -> queen at raw 2 , column 3 
    int solutionCount; 
    
    
    
    // Check if placing a queen at (row, col) is safe given the previous queens placed in previous rows 0 .. row-1.

    bool isSafe(int row, int col) const{
        for (int i=0; i<row ; i++){
            // same column OR same diagonal OR same cross diagonal?
            // previous queen at (i, board[i]) and candidate (row, col) 
            // Row difference: |i - row|
            // Column difference: |board[i] - col|
            // If these are equal, the squares lie on the same \ diagonal or / diagonal
            if (board[i] == col || abs(board[i] - col) == abs(i - row))
                //cout << "Queen under attack !"<< endl;
                return false;
        }
        // If none of the previous queens conflict, the function returns true
        //cout << "Queen safe !"<< endl;
        return true;
    }
    
    
    
    
    // Recursive backtracking function
    
    void solve(int row){
        if (row == N){
            // Base case: all rows are filled
            // If row == N we've placed queens in all rows 0..N-1
            solutionCount++;
            printBoard();
            return;  // prevents running the loop below
        }
        
        // Try every column in the current row
        for (int col=0; col<N ; col++){
            
            // Prune invalid choices : if not safe the coulmn will be skipped 
            // Backtracking always cleans up after itself — success or failure.
            if(isSafe(row,col)){
                board[row]=col;   // PLACE
                solve(row+1);     // EXPLORE : recursively solve for the next row 
                board[row]=-1;    // // undo and try a DIFFERENT choice
            }
            
            
        }
    }
        
        
     // Print current board configuratio 
     // const: this function does NOT modify class data
     // i:row j:column
     // condition ? value_if_true : value_if_false
     void printBoard() const {
         for (int i=0; i<N ; i++){
             for(int j=0; j<N; j++){
                 cout << (board[i] == j ? "Q " : ". ");
             }
              cout << endl;
         }
          cout << endl;
     }
    
        
public:

        
    NQueens(int n) {
        N = n;                 // set board size
        board.resize(n, -1);   // create board and fill with -1
        solutionCount = 0;     // no solutions yet
    }
    
    
        
    // Solve the N-Queens problem
    void solve() {
        solve(0);
        cout << "Total solutions: " << solutionCount << endl;
    }
        
    
                

    
}; // End of the class





int main() {
    int N;
    cout << "Enter the value of N: \n";
    cin >> N;

    NQueens solver(N);
    solver.solve();

    return 0;
}







