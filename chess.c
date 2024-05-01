// By: Corey T
#include <stdio.h>
#include <string.h>

// constant for the chess board dimeensions
const int EIGHT = 8;
const int TWO = 2;

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

// function for displaying the starting chess board to visualize it
void display_board()
{
    for (int row = 0; row < EIGHT; row++)
    {
        for (int column = 0; column < EIGHT; column++)
        {
            printf("%s ", board[row][column]);
        }
        printf("\n");
    }

}


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




    return 0;
}
