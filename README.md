By Corey T
# project3


DATA STRUCTURES:

Chessboard representation:
For my chessboard inplementaion I decided to use a 2D array to represnt this structure.
This 2D array is of type Char* and is represented like this: char* board[EIGHT][EIGHT]. The
'EIGHT' is a const global int variable. The reason why I went with is data structure is because i believe that it is the easiest way to think/visualize the chessboard. It allowed my to easily understand conceptually how I could approach coding solution and implement specific algorithms (searching, moves, deletes, etc).

Piece Encoding:
Each chess piece has a specific type (pawn, queen, bishop, etc) and color (white or black). To code this I decided to use the enum type to reprent both the color types and the piece rank types. I have an enum structure called color that is comprised of two constants (white and black). I have another enum structure called type that represents that rank peice options comprised of constants. Each consant is set equal to a its coresponding char letter. For example, KING = 'k' and PAWN = 'P'. Finally, I have a struct called Piece that is comprised of both the color enum and type enum as member variables.



Game state management:





MOVE VALIDATION:






