/******************************************************************************

                              NQueens!


*******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class NQueens {
private:
    int N;
    vector<int> board; // board[i] = column of queen in row i
    int solutionCount;

    // Check if placing a queen at (row, col) is safe
    bool isSafe(int row, int col) const {
        for (int i = 0; i < row; i++) {
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
    NQueens(int n) : N(n), board(n, -1), solutionCount(0) {}

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




