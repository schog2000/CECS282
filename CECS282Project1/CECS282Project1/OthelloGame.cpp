#include "OthelloGame.h"
#include <iostream>
#include <array>

void PrintBoard(const OthelloMatrix &board) {
	std::cout << "- 0 1 2 3 4 5 6 7\n";
	for (int i = 0;i < 8;i++) {
		std::cout << i << " ";
		for (int j = 0;j < 8;j++) {
			if (board[i][j] == 0) {
				std::cout << ". ";
			}
			else if (board[i][j] == 1) {
				std::cout << "B ";
			}
			else if (board[i][j] == -1){
				std::cout << "W ";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
void GetMove(int &row, int &col) {
	char dummy, dummy1, dummy2;
	std::cin >> dummy >> row >> dummy1 >> col >> dummy2;
}
bool InBounds(int row, int col) {
	bool checker = (row < 8 && row >= 0) && (col < 8 && col >= 0);
	return checker;
}
bool IsValidMove(const OthelloMatrix &board, int row, int col) {
	bool checker = ((row == -1 && col == -1) || (InBounds(row, col) && board[row][col] == 0));
	return checker;
}
void ApplyMove(OthelloMatrix &board, int row, int col, char currentPlayer) {
	board[row][col] = currentPlayer;
	std::array<char, 8> adjR = { -1, 0, 1, 1, 1, 0, -1, -1 };
	std::array<char, 8> adjC = { -1, -1, -1, 0, 1, 1, 1, 0 };

	for (int k=0; k < 8;k++) {
		while (k < 8 && (row + adjR[k] < 0 || row + adjR[k] > 7 || col + adjC[k] < 0 || col + adjC[k] > 7)) {
			k++;
		}
		if (k < 8 && (board[row + adjR[k]][col + adjC[k]] != currentPlayer && board[row + adjR[k]][col + adjC[k]] != 0)) {
			int rowC = row;
			int colC = col;
			while (board[rowC][colC] != currentPlayer || rowC >= 0 && rowC <= 7 || colC >= 0 && colC <= 7) {
				rowC = rowC + adjR[k];
				colC = colC + adjC[k];
				if (rowC < 0 || rowC > 7 || colC < 0 || colC > 7) {
					break;
				}
				if (board[rowC][colC] == currentPlayer) {
					while (rowC != row || colC != col) {
						rowC = rowC - adjR[k];
						colC = colC - adjC[k];
						board[rowC][colC] = currentPlayer;
					}
					break;
				}
			}
		}
	}
}
int GetValue(const OthelloMatrix &board) {
	int count = 0;
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			count = count + board[i][j];
		}
	}
	return count;
}