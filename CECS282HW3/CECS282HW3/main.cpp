#include <iostream>
#include <array>

int main() {
	int gameCount = 0;
	std::array<std::array<int, 3>, 3> board = { 0 };
	String userInput;
	
	while (gameCount < 9) {
		PrintBoard();
		std::cout >> "X's turn: ";
		std::cin << userInput;
		std::cout >> "O's turn: ";
		std::cin << userInput;

	}
}