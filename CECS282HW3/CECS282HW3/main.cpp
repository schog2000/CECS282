#include "tictactoe.h"
#include <iostream>
#include <array>

void PrintBoard(const std::array<std::array<char, 3>, 3> &board);
void GetMove(int &row, int &col);
bool MoveIsValid(const std::array<std::array<char, 3>, 3> &board, int row, int col);
char CheckWinner(const std::array<std::array<char, 3>, 3> &board);

int main() {
	int movesTotal = 0;
	std::array<std::array<char, 3>, 3> board = { 0 };
	int row, col;
	int playerTurn = 1;
	int winner = 0;


	while (movesTotal < 9) {
		PrintBoard(board);
		if (playerTurn == 1) {
			std::cout << "X's turn: ";
			GetMove(row, col);
			while (MoveIsValid(board, row, col) == false) {
				if (row > 2 || col > 2 || row < 0 || col < 0) {
					std::cout << "Out of bounds input.\n";
					std::cout << "X's turn: ";
					GetMove(row, col);
				}
				std::cout << "That space is already taken!\n";
				std::cout << "X's turn: ";
				GetMove(row, col);
			}
			board[row][col] = playerTurn;
			std::cout << "\n";
			if (CheckWinner(board) == 1) {
				std::cout << "Player X wins!\n";
				winner = 1;
				break;
			}
			playerTurn = playerTurn - 2;
		}
		else {
			std::cout << "O's turn: ";
			GetMove(row, col);
			while (MoveIsValid(board, row, col) == false) {
				if (row > 2 || col > 2 || row < 0 || col < 0) {
					std::cout << "Out of bounds input.\n";
					std::cout << "O's turn: ";
					GetMove(row, col);
				}
				std::cout << "That space is already taken!\n";
				std::cout << "O's turn: ";
				GetMove(row, col);
			}
			board[row][col] = playerTurn;
			std::cout << "\n";
			if (CheckWinner(board) == -1) {
				std::cout << "Player O wins!\n";
				winner = -1;
				break;
			}
			playerTurn = playerTurn + 2;
		}
		movesTotal++;
	}
	if (winner == 0) {
		PrintBoard(board);
		std::cout << "Draw\n";
	}
}