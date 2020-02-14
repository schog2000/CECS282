#include "tictactoe.h"
#include <iostream>
#include <array>

void PrintBoard(const std::array<std::array<char, 3>, 3> &board) {
	std::cout << "- 0 1 2\n";
	for (int i = 0;i<3;i++) {
		std::cout << i << " ";
		for (int j=0;j<3;j++) {
			if (board[i][j] == 0) {
				std::cout << ". ";
			}
			else if (board[i][j] == 1) {
				std::cout << "X ";
			}
			else {
				std::cout << "O ";
			}
		}
		std::cout << "\n";
	}
}
void GetMove(int &row, int &col) {
	char dummy;
	std::cin >> row >> dummy >> col;
}
bool MoveIsValid(const std::array<std::array<char, 3>, 3> &board, int row, int col) {
	bool checker;
	if (row > 2 || col > 2 || row < 0 || col < 0) {
		return false;
	}
	if (board[row][col] != 0) {
		checker = false;
	}
	if (board[row][col] == 0) {
		checker = true;
	}
	return checker;
}
char CheckWinner(const std::array<std::array<char, 3>, 3> &board) {
	int checker = 0;
	for (int i = 0;i < 3;i++) {
		if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
			checker = 1;
		}

		if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1) {
			checker = 1;
		}
		if (board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1) {
			checker = -1;
		}

		if (board[0][i] == -1 && board[1][i] == -1 && board[2][i] == -1) {
			checker = -1;
		}
	}
	if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
		checker = 1;
	}
	if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
		checker = 1;
	}
	if (board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1) {
		checker = -1;
	}

	if (board[0][2] == -1 && board[1][1] == -1 && board[2][0] == -1) {
		checker = -1;
	}
	return checker;
}