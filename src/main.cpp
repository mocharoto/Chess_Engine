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
	// Do these need to be on the heap?
	board::Square **tile = new board::Square*[board::sizeY];

	for (int index = 0; index < board::sizeY; ++index)
	{
		tile[index] = new board::Square[board::sizeX];
	}

	Chessboard.initializeBoard(tile);

	auto testPawn = new Pawn();
	testPawn->setPosition(coord{0, 3}, tile);
	std::cout << testPawn->getPieceName() << " " << testPawn->getPosition().x << " " << testPawn->getPosition().y << std::endl;

	coordList validMoves;

	validMoves = testPawn->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}

	auto testKnight = new Knight();
	testKnight->setPosition(coord{0, 3}, tile);
	std::cout << "Knight at: " << testKnight->getPosition().x << " " << testKnight->getPosition().y << std::endl;

	validMoves = testKnight->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}

	auto testBishop = new Bishop();
	testBishop->setPosition(coord{2, 2}, tile);
	std::cout << "Bishop at: " << testBishop->getPosition().x << " " << testBishop->getPosition().y << std::endl;

	validMoves = testBishop->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}
	//Chessboard.placePiece("Pawn1", testPawn->getPosition().x, testPawn->getPosition().y, tile);
	//Chessboard.placePiece("Knight1", testPawn->getPosition().x, testPawn->getPosition().y, tile);


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

	// Do we need to delete pointers if we are exiting?
	/*
	std::cout << "pause here" << std::endl;


	for (int index = 0; index < board::sizeY; ++index)
	{
		delete[] tile[index];
	}

	delete[] tile;
	*/
	return 0;
}
