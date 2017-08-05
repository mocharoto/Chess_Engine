//Author: Julian Yi
//Date Started: 14 July 2017, Friday.
//Purpose: This is a project to create a working chess engine and gui using C++.
//File: This is the main file.
#include <iostream>
#include "board.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "coord.h"
#include "BearLibTerminal.h"
int main()
{
	board Chessboard;

	Chessboard.initializeBoard();

	Chessboard.placePiece(PieceType::Pawn, {5, 5}, TeamColor::White);
	Chessboard.placePiece(PieceType::Knight, {1, 2}, TeamColor::White);
	Chessboard.placePiece(PieceType::Bishop, {2, 3}, TeamColor::Black);

	// Test deleting.
	Chessboard.deletePiece({5, 5});

	// Test a regular move.
	Chessboard.movePiece({2, 3}, {3, 4});

	// Test an attack.
	Chessboard.movePiece({3, 4}, {1, 2});
	
	// Open the terminal. Since no terminal_set() method is called,
	// the terminal will use default settings.
	terminal_open();

	// Print intro text.
	terminal_print(1, 1, "Chess Engine");
	terminal_print(4, 2, "by Julian Yi, Sean Brock, and Simon Kim");
	terminal_print(1, 4, "Press Enter to start...");
	terminal_refresh();

	bool running = true;
	while (running) {
		// Check for input. termnial_read() is blocking, meaning the
		// program will wait until it reads a key press.
		auto key = terminal_read();

		// Reset the terminal to blank state.
		terminal_clear();

		// Print instructions.
		terminal_print(1, 1, "Press Enter to start...");

		// Handle key presses.
		switch (key) {
			case TK_CLOSE:
				running = false;
				break;
			case TK_ESCAPE:
				running = false;
				break;
			case TK_ENTER:
				terminal_print(1, 2, "Simon is king; Kylee is queen.");
				break;
			default:
				terminal_print(1, 2, "The key pressed has no function.");
				break;
		}

		// Commit the buffer and draw it.
		terminal_refresh();

	}

	// We're done here.
	terminal_close();

	return 0;
}
