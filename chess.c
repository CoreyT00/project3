// By: Corey T
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define EIGHT 8


// defining the chess board as a 2D char array
// and intializing starting piece position
char *board[EIGHT][EIGHT] = {
    {"WR", "WN", "WB", "WQ", "WK", "WB", "WN", "WR"},
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
typedef enum
{
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
void pawn_move(char* board[EIGHT][EIGHT], int start_row, int start_col, int end_row, int end_col)
{
    // strings used to to find the indexes of the target position and
    // the piece that is requested to be moved
    char* piece = board[start_row][start_col];
    char* target = board[end_row][end_col];

    // Check if the target square is empty
    if (strcmp(target, "**") == 0) {
        // Check if the move is one square forward
        if (start_col == end_col && start_row + 1 == end_row) {
            // Update the board
            board[end_row][end_col] = piece;
            board[start_row][start_col] = "**";
            return;
        }
        // Check if it's the first move and the pawn moves two squares forward
        if (start_col == end_col && start_row == 1 && end_row == 3) {
            // Check if the intermediate square is empty
            if (strcmp(board[2][start_col], "**") == 0) {
                // Update the board
                board[end_row][end_col] = piece;
                board[start_row][start_col] = "**";
                return;
            }
        }
    } else {
        // Check if the move is a diagonal capture
        if (abs(start_col - end_col) == 1 && start_row + 1 == end_row) {
            // Update the board
            board[end_row][end_col] = piece;
            board[start_row][start_col] = "**";
            return;
        }
    }

    // If none of the above conditions are met, the move is illegal
    illegal();
}







// method for legal moves for rook pieces
void rook_move(char* board[EIGHT][EIGHT], int start_row, int start_col, int end_row, int end_col)
{

     // strings used to to find the indexes of the target position and
    // the piece that is requested to be moved
    char* piece = board[start_row][start_col];
    char* target = board[end_row][end_col];

    // Check if the move is along a row or column
    if (start_row == end_row || start_col == end_col)
    {
        // Check if there are any pieces blocking the rook's path
        int row_step = (start_row == end_row) ? 0 : (start_row < end_row) ? 1 : -1;
        int col_step = (start_col == end_col) ? 0 : (start_col < end_col) ? 1 : -1;

        int current_row = start_row + row_step;
        int current_col = start_col + col_step;

        while (current_row != end_row || current_col != end_col)
        {
            if (strcmp(board[current_row][current_col], "**") != 0)
            {
                illegal();
                return;
            }

            current_row += row_step;
            current_col += col_step;
        }

        // Update the board if the path is clear
        board[end_row][end_col] = piece;
        board[start_row][start_col] = "**";
    }
    else
    {
        // If none of the above conditions are met, the move is illegal
        illegal();
    }
}






// Function to check if a move is legal for a bishop
void bishop_move(char* board[EIGHT][EIGHT], int start_row, int start_col, int end_row, int end_col)
{
    // Check if the move is along a diagonal
    if (abs(start_row - end_row) == abs(start_col - end_col))
    {
        // Determine the direction of the diagonal
        int row_step = (start_row < end_row) ? 1 : -1;
        int col_step = (start_col < end_col) ? 1 : -1;

        int current_row = start_row + row_step;
        int current_col = start_col + col_step;

        while (current_row != end_row || current_col != end_col)
        {
            if (strcmp(board[current_row][current_col], "**") != 0)
            {
                illegal();
                return;
            }

            current_row += row_step;
            current_col += col_step;
        }

        // Update the board if the path is clear
        board[end_row][end_col] = board[start_row][start_col];
        board[start_row][start_col] = "**";
    }
    else
    {
        illegal();
    }
}







// Function to check if a move is legal for a queen
void queen_move(char* board[EIGHT][EIGHT], int start_row, int start_col, int end_row, int end_col)
{
    // A queen can move like a rook or a bishop
    if (start_row == end_row || start_col == end_col || abs(start_row - end_row) == abs(start_col - end_col))
    {
        // Check if there are any pieces blocking the queen's path
        int row_step = (start_row == end_row) ? 0 : (start_row < end_row) ? 1 : -1;
        int col_step = (start_col == end_col) ? 0 : (start_col < end_col) ? 1 : -1;

        int current_row = start_row + row_step;
        int current_col = start_col + col_step;

        while (current_row != end_row || current_col != end_col)
        {
            if (strcmp(board[current_row][current_col], "**") != 0)
            {
                illegal();
                return;
            }

            current_row += row_step;
            current_col += col_step;
        }

        // Update the board if the path is clear
        board[end_row][end_col] = board[start_row][start_col];
        board[start_row][start_col] = "**";
    }
    else
    {
        illegal();
    }
}







// Function to check if a move is legal for a knight
void knight_move(char* board[EIGHT][EIGHT], int start_row, int start_col, int end_row, int end_col)
{
    // Check if the move is an L shape (2 squares in one direction, 1 square in another)
    int row_delta = abs(end_row - start_row);
    int col_delta = abs(end_col - start_col);

    if ((row_delta == 2 && col_delta == 1) || (row_delta == 1 && col_delta == 2))
    {
        // Check if the destination square is empty or has an opponent's piece
        if (strcmp(board[end_row][end_col], "**") == 0 || board[start_row][start_col]->color != board[end_row][end_col]->color)
        {
            // Update the board
            board[end_row][end_col] = board[start_row][start_col];
            board[start_row][start_col] = "**";
        }
        else
        {
            illegal();
        }
    }
    else
    {
        illegal();
    }
}

// Function to check if a move is legal for a king
void king_move(char* board[EIGHT][EIGHT], int start_row, int start_col, int end_row, int end_col)
{
    // Check if the move is within one square in any direction
    int row_delta = abs(end_row - start_row);
    int col_delta = abs(end_col - start_col);

    if (row_delta <= 1 && col_delta <= 1)
    {
        // Check if the destination square is empty or has an opponent's piece
        if (strcmp(board[end_row][end_col], "**") == 0 || board[start_row][start_col]->color != board[end_row][end_col]->color)
        {
            // Update the board
            board[end_row][end_col] = board[start_row][start_col];
            board[start_row][start_col] = "**";
        }
        else
        {
            illegal();
        }
    }
    else
    {
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
        pawn_move(board, result.row, result.column, new_row, new_col);
    }

}




// function for displaying the starting chess board to visualize it
void display_board(char* board[EIGHT][EIGHT])
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

// defining the chess board as a 2D char array
// and intializing starting piece position
char *board[EIGHT][EIGHT] = {
    {"WR", "WN", "WB", "WQ", "WK", "WB", "WN", "WR"},
    {"WP", "WP", "WP", "WP", "WP", "WP", "WP", "WP"},
    {"**", "**", "**", "**", "**", "**", "**", "**"},
    {"**", "**", "**", "**", "**", "**", "**", "**"},
    {"**", "**", "**", "**", "**", "**", "**", "**"},
    {"**", "**", "**", "**", "**", "**", "**", "**"},
    {"BP", "BP", "BP", "BP", "BP", "BP", "BP", "BP"},
    {"BR", "BN", "BB", "BQ", "BK", "BB", "BN", "BR"},
};








    // string for user input command
    char* user_input = malloc(20);

    // string for parsing command number
    char* command_num = malloc(3);

    // do while loop that will iterate until the game ends or the user resigns
    do
    {
        printf("\n\nEnter a command: ");
        fgets(user_input, sizeof(user_input), stdin);

        printf("\nThe user enterered: '%s'", user_input);
        // copying the command values to another variable
        strncpy(command_num, user_input, 2);
        //command_num[2] = '\0';



        // case if user begins a new game
        // only works if the user inputs "00 W" or "00 B"
        // error handling otherwise
        if (strcmp(command_num, "00") == 0)
        {
            printf("Inside 00 case\n");
            if(user_input[4] == 'W')
            {
                printf("\nstarting new game as white\n");
            }
            else if (user_input[4] == 'B')
            {
                printf("\nstarting new game as black\n");
            }
            else
            {
                printf("\nError: Invalid input for color (use 'W' or 'B')\n");
            }
        }
        else
        {
            printf("\nError: Command not recognized\n");
        }






        // case if the user wants to check the game status
        if(strcmp(command_num, "01") == 0)
        {
            printf("\n");
            display_board(board);
            printf("\n");

        }



        // case if the user request to move a piece
        if(strcmp(command_num, "02") == 0)
        {
            move(board, "WP", 2, 0);
            display_board(board);
            move(board, "WP", 3, 6);
            display_board(board);

        }



        // case if for the cpu to move
        if(strcmp(command_num, "03") == 0)
        {

        }


        // case to resign game
        if(strcmp(command_num, "04") == 0)
        {
            printf("\n");
            printf("OK\n");
        }


    } while (strcmp(command_num, "04") != 0);




    free(user_input);
    free(command_num);

    return 0;
}
