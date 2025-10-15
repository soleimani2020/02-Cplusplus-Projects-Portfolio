# 🎮 Tic-Tac-Toe Game in C++

This C++ project implements a **two-player Tic-Tac-Toe game** on a 3x3 board using a class-based structure.  

Players alternately place their marks (**X** or **O**) on the board until one player wins or the game ends in a draw.  

---

## ⚙️ Class Overview

### `ticTacToe`
Represents the Tic-Tac-Toe game.

**Private Attributes:**
- `board[3][3]` – Stores the current state of the board  
- `Current_player` – Tracks whose turn it is  

**Public Methods:**
- `Set_Board_game()` – Initializes the board with empty spaces  
- `Display_Board_game()` – Displays the current state of the board  
- `Player_Switch()` – Switches the current player between **X** and **O**  
- `CheckWinningMoves()` – Checks if the current player has a winning combination (rows, columns, diagonals)  
- `CheckDraw()` – Checks if the board is full and the game is a draw  
- `PlayGame()` – Implements the main game loop  

---

## 🖥️ Example Gameplay

```text
Welcome to our little game!
Player X please make a move!
Please Enter the row (0-2):
0
Please Enter the column (0-2):
0
X |   |  
----------
  |   |  
----------
  |   |  
Player O please make a move!
...
Player X has won the game! Hooray!
End of the game
