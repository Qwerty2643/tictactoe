#include <stdio.h>

// Function declarations
void displayBoard(char board[3][3]);
int checkWin(char board[3][3]);
int isDraw(char board[3][3]);

// Main function
int main() {
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int player = 1, choice, row, col;
    char mark;
    int gameStatus = 0;  // 0 = ongoing, 1 = win, -1 = draw
    
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n");
    
    while (gameStatus == 0) {
        // Display the board
        displayBoard(board);
        
        // Switch between player 1 and player 2
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';
        
        // Ask for player input
        printf("\nPlayer %d, enter your move (1-9): ", player);
        scanf("%d", &choice);
        
        // Map the choice to the board position
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
        
        // Check if the chosen position is valid
        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = mark;
        } else {
            printf("Invalid move! Try again.\n");
            player--;  // Allow the same player to retry
            continue;
        }
        
        // Check for win or draw
        gameStatus = checkWin(board);
        if (gameStatus == 0 && isDraw(board)) {
            gameStatus = -1;  // It's a draw
        }
        
        player++;
    }
    
    // Display the final board and result
    displayBoard(board);
    if (gameStatus == 1) {
        printf("\nCongratulations, Player %d wins!\n", --player);
    } else {
        printf("\nIt's a draw!\n");
    }
    
    return 0;
}

// Function to display the board with formatting
void displayBoard(char board[3][3]) {
    printf("\n     |     |     \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("  %c  ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n_ _ _ _ _ _ _ _ _ \n     |     |     \n");
    }
    printf("\n     |     |     \n");
}

// Function to check if there's a winner
int checkWin(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    
    return 0;  // No winner yet
}

// Function to check if the game is a draw
int isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return 0;
        }
    }
    return 1;  // It's a draw
}
