/******************************************************************************

                              OTic tac toe.


1. we need a board game (3*3) -> define -> show  
2. we need two players ( switch player function ): 
   current player ---> next player
3. we need to know winning condition (check for winner):
    / Check Raws 
    / Check columns 
    / Check diagonals 

4. check if the game is a draw 
5. If the board has empty spots, then some one has one ! otherwise it is a draw
6. while (invalid move -> n,m >=3) , ask for the right move !  

*******************************************************************************/

#include <iostream>
using namespace std;
 

class ticTacToe{
    
    private:
        char board[3][3];
        char Current_player;

    public:
    
        void Set_Board_game(){
            for (int i=0; i<3 ; i++){
                for (int j=0; j<3;j++){
                    board[i][j]=' ';
                    }
                }
        }
        
        
    
        void Display_Board_game(){
            for (int i=0; i<3 ; i++){
                for (int j=0; j<3;j++){
                    cout << board[i][j];
                    if (j<2){
                        cout << " | "; ;
                    }
                }
                
            cout << endl;
            if (i<2){
                cout << "----------" << endl;
            }    
            
            }
        }
        
        
        void Player_Switch(){
            if (Current_player == 'X'){
                Current_player = 'O';
            }else{
                Current_player = 'X';
            }
        }
        
        
        int CheckWinningMoves() {
            // Check Rows and Columns
            for (int i = 0; i < 3; i++) {
                if ((board[i][0] == Current_player && board[i][1] == Current_player && board[i][2] == Current_player) ||
                    (board[0][i] == Current_player && board[1][i] == Current_player && board[2][i] == Current_player)) {
                    return 1;
                }
            }
        
            // Check Diagonals
            if ((board[0][0] == Current_player && board[1][1] == Current_player && board[2][2] == Current_player) ||
                (board[0][2] == Current_player && board[1][1] == Current_player && board[2][0] == Current_player)) {
                return 1;
            }
        
            return 0;  // Return 0 if no winning moves
        }

        
        
        int CheckDraw(){
            for (int i=0; i < 3; i++){
                for (int j=0; j < 3; j++){
                    if (board[i][j] == ' '){
                        return 0;
                        // someone has one 
                    }
  
                }
            }
            
            return 1;
            // Draw
        }
        
        void PlayGame(){
            int n, m;
            Current_player = 'X';
            Set_Board_game();  // Initialize the board
            
            while(true){
                Display_Board_game();
                cout << "Player " << Current_player << " please make a move!" << endl;
                cout << "Please Enter the row (0-2): " << endl;
                cin >> m;
                cout << "Please Enter the column (0-2): " << endl;
                cin >> n;
                
                // Validate the move
                if (m < 0 || m >= 3 || n < 0 || n >= 3) {
                    cout << "This is not a valid move! Please enter a row and column between 0 and 2." << endl;
                    continue;
                }
                    
                // Cell should be empty 
                if (board[m][n] != ' ') {
                    cout << "This cell is already taken!" << endl;
                    continue;
                }
                
                // Place the current player's move on the board
                board[m][n] = Current_player;
                
                // Check if the current player has won
                if (CheckWinningMoves()) {
                    Display_Board_game();
                    cout << "Player " << Current_player << " has won the game! Hooray!" << endl;
                    break;
                }
    
                // Check for a draw
                if (CheckDraw()) {
                    Display_Board_game();
                    cout << "The game is a draw!" << endl;
                    break;
                }
                
                // Switch to the other player
                Player_Switch();






              
       
             }
        }

}; 



int main()
{
    ticTacToe game;
    cout << "Welcome to our little game!" << endl;
    game.PlayGame();
    cout << "End of the game"<< endl;
    return 0;
}



// Important note : Although "Current_player" is private, it can be accessed inside the class by function members of the class. Howeverr, it can not be accesssed out side of the class directly.




















