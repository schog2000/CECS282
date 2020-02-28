#include "OthelloGame.h"
#include <iostream>
#include <array>

int main() {
	OthelloMatrix board = { 0 };
	board[3][3] = -1;
	board[3][4] = 1;
	board[4][3] = 1;
	board[4][4] = -1;
	int row, col; 
    char currentPlayer = 1;
	int passMeter = 0;


	while (passMeter < 2) {
		PrintBoard(board);
		if (currentPlayer == 1) {
			std::cout << "Black's turn: ";
			GetMove(row, col);
			if (row == -1 && col == -1) {
				passMeter++;
				currentPlayer = currentPlayer - 2;
				continue;
			}
			else if (passMeter == 1 && (row != -1 && col != -1)) {
				passMeter = 0;
			}
			if (!IsValidMove(board, row, col)) {
				std::cout << "Invalid move!\n\n";
				continue;
			}
			ApplyMove(board, row, col, currentPlayer);
			currentPlayer = currentPlayer - 2;
		}
		else {
			std::cout << "White's turn: ";
			GetMove(row, col);
			if (row == -1 && col == -1) {
				passMeter++;
				currentPlayer = currentPlayer + 2;
				continue;
			}
			else if (passMeter == 1 && (row != -1 && col != -1)) {
				passMeter = 0;
			}
			if (!IsValidMove(board, row, col)) {
				std::cout << "Invalid Move!\n\n";
				continue;
			}
			ApplyMove(board,row,col,currentPlayer);
			currentPlayer = currentPlayer + 2;
		}
	}
	int tally = GetValue(board);
	if (tally > 0) {
		std::cout << "Black wins\n";
	}
	else if (tally < 0) {
		std::cout << "White wins\n";
	}
	else {
		std::cout << "Draw\n";
	}
}