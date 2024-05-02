// By: Corey T
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define EIGHT 8


// defining the chess board as a 2D char array
// and intializing starting piece position
char* board[EIGHT][EIGHT] = {
    {"WR", "WN", "WB", "WQ","WK", "WB", "WN", "WR"},
    {"WP", "WP", "WP", "WP", "WP", "WP", "WP", "WP"},
    {"**", "**", "**", "**", "**", "**", "**", "**"},
    {"**", "**", "**", "**", "**", "**", "**", "**"},
    {"**", "**", "**", "**", "**", "**", "**", "**"},
    {"**", "**", "**", "**", "**", "**", "**", "**"},
    {"BP", "BP", "BP", "BP", "BP", "BP", "BP", "BP"},
    {"BR", "BN", "BB", "BQ", "BK", "BB", "BN", "BR"},
};


// struct used to indicate the the row and column of the chessboard
typedef struct Index
{
    int row;
    int column;
} Index;


// enum used to represnt the chess peice types
typedef enum {
    KING = 'K',QUEEN = 'Q',BISHOP = 'B',
    KNIGHT = 'N',ROOK = 'R',PAWN = 'P'
} Type;

// enum type used to represent the color of the peice type
typedef enum {BLACK, WHITE}Color;

// defining a struct used to represent a chess piece type and color
typedef struct Piece
{
    Color color;
    Type type;

}Piece;



// function used for searching for a player's chess piece
Index search (char* grid[EIGHT][EIGHT], char* target)
{


    // intializing the index to -1, -1 before searching for value
    Index index;
    index.row = -1;
    index.column -1;

    // algorithm for searching for the target peice
    for (int i = 0; i < EIGHT; i++)
    {
        for (int j = 0; j < EIGHT; j++)
        {
            if (strcmp(grid[i][j], target) == 0)
            {
                index.row = i;
                index.column = j;
                return index;
            }
        }
    }

    return index;
}






// method to change positions with
void swap_positions(int src_row, int src_col, int dest_row, int dest_col)
{
    char* temp = board[dest_row][dest_col];
    board[dest_row][dest_col] = board[src_row][src_col];
    board[src_row][src_col] = temp;
}


// method indicating that a move was illigal
void illegal()
{
    printf("ILLMOVE\n");
}

// method for legal moves for pawn pieces
void pawn_move(char* board[EIGHT][EIGHT], int row, int column)
{
    if (row == 1 && strcmp(board[row + 1][column], "**") == 0)
    {
        // allow the move
        printf("");


    }
    else
    {
        // the move is illegal
        illegal();
    }


}

// method to execute a move operation
void move(char* board[EIGHT][EIGHT], char* target, int new_row, int new_col)
{

    Index result;
    result = search(board, target);

    if (result.row == -1 || result.column == -1)
    {
        printf("Piece not found on the board.\n");
        return;
    }

    if(strcmp(target,"WP") == 0 || strcmp(target, "BP") == 0)
    {
        pawn_move(board, new_col, new_col);
         swap_positions(result.row, result.column, new_row, new_col);
    }

}




// function for displaying the starting chess board to visualize it
void display_board()
{
    for (int row = 0; row < 8; row++)
    {
        for (int column = 0; column < 8; column++)
        {
            printf("%s ", board[row][column]);
        }
        printf("\n");
    }

}







// this function hndles all chess move operations based on user input
void write ()
{
    // used to indicate if the game is still on (1 for on , 0 if ended)
    int game_status = 1;
    // string for user input 1
    char* user_input1;






}

// main function for the program
int main()
{
    display_board();

    // index object used for testing
    Index result;

    // searching for test value
    result = search(board, "BQ");

    printf("\n\nThe row index value of BQ is: %d\n The column index value of BQ is: %d\n\n", result.row, result.column);

    move(board, "WP", 2, 0);

    display_board();

    move(board, "BP", 6, 0);

    display_board();


    return 0;
}
