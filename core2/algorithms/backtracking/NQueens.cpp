/******************************************************************************

                              NQueens!


*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class NQueens {
private:
    int N; // board size 
    vector<int> board; // board[i] = column of queen in row i : board[2] = 3 → queen at (row 2, column 3)
    int solutionCount;  // counting valid solutions 

    // Check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col) const {
        for (int i = 0; i < row; i++) {
            // Column conflict  || Diagonal conflict 
            if (board[i] == col || abs(board[i] - col) == abs(i - row))
                return false;
        }
        return true;
    }

    // Recursive backtracking function
    void solve(int row) {
        if (row == N) {
            solutionCount++;
            printBoard();
            return;
        }

        for (int col = 0; col < N; col++) {
            if (isSafe(row, col)) {
                board[row] = col;
                solve(row + 1);
                board[row] = -1; // backtrack
            }
        }
    }

    // Print current board configuration
    void printBoard() const {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
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
};




int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    NQueens solver(N);
    solver.solve();

    return 0;
}




