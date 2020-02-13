#include <array>

// PrintBoard takes a 2-dimensional array parameter representing the game state
// and prints it to cout. See the spec for details on formatting the output.
void PrintBoard(const std::array<std::array<char, 3>, 3> &board);

// GetMove uses cin to read the user's choice for where to move next on the 
// board. It does NOT update the game board with the move choice; it simply
// scans in values to the row and col variables, which will update whatever
// variables were used as arguments in the main. Do not check move validity
// in this function.
void GetMove(int &row, int &col);

// MoveIsValid returns true if the board is empty at the requested row/col,
// and false otherwise. Used in main to see if the move is valid and alert
// the user if it is not.
bool MoveIsValid(const std::array<std::array<char, 3>, 3> &board, 
    int row, int col);

// CheckWinner returns looks to see if the game has a winner. It returns 
// 1 if player 1 is the winner, -1 if player 2 is the winner, or 0
// if there is no winner -- either because the game is a draw, or because
// the game is not over yet.
char CheckWinner(const std::array<std::array<char, 3>, 3> &board);