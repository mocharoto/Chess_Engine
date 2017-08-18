//Author: Julian Yi
//Date Started: 14 July 2017, Friday.
//Purpose: This is a project to create a working chess engine and gui using C++.
//File: This is the main file.
#include <iostream>
#include "statemanager.h"
#include "BearLibTerminal.h"
#include "ui.h"

int main()
{


	// Initialize board.
	auto Chessboard = std::make_shared<board>();
	Chessboard->initializeBoard();

	for (int i = 0; i < 8; i++) {
		Chessboard->placePiece(PieceType::Pawn, {i, 1}, TeamColor::White);
	}

	Chessboard->placePiece(PieceType::Rook, {0, 0}, TeamColor::White);
	Chessboard->placePiece(PieceType::Rook, {7, 0}, TeamColor::White);
	Chessboard->placePiece(PieceType::Knight, {1, 0}, TeamColor::White);
	Chessboard->placePiece(PieceType::Knight, {6, 0}, TeamColor::White);
	Chessboard->placePiece(PieceType::Bishop, {2, 0}, TeamColor::White);
	Chessboard->placePiece(PieceType::Bishop, {5, 0}, TeamColor::White);
	Chessboard->placePiece(PieceType::Queen, {3, 0}, TeamColor::White);
	Chessboard->placePiece(PieceType::King, { 4,0 }, TeamColor::White);

	for (int i = 0; i < 8; i++) {
		Chessboard->placePiece(PieceType::Pawn, {i, 6}, TeamColor::Black);
	}
	Chessboard->placePiece(PieceType::Rook, {0, 7}, TeamColor::Black);
	Chessboard->placePiece(PieceType::Rook, {7, 7}, TeamColor::Black);
	Chessboard->placePiece(PieceType::Knight, {1, 7}, TeamColor::Black);
	Chessboard->placePiece(PieceType::Knight, {6, 7}, TeamColor::Black);
	Chessboard->placePiece(PieceType::Bishop, {2, 7}, TeamColor::Black);
	Chessboard->placePiece(PieceType::Bishop, {5, 7}, TeamColor::Black);
	Chessboard->placePiece(PieceType::Queen, {3, 7}, TeamColor::Black);
	Chessboard->placePiece(PieceType::King, { 4,7 }, TeamColor::Black);

	std::string settings =
		"window:"
			"title='Chess',"
			"size='" + std::to_string(windowSize::x) + "x" + std::to_string(windowSize::y) + "';"
		"font: ./font/FSEX300.ttf,"
			"size=32x32;"
		"palette:"
			"whitepiece=#C2CCCF,"
			"blackpiece=#4D483C,"
			"whitetile=#02171F,"
			"blacktile=#000000;"
		"input:"
			"cursor-symbol = 0x1F,"
			"cursor-blink-rate = 500,"
			"precise-mouse = false,"
			"mouse-cursor = true,"
			"filter=[keyboard, mouse];"
	;

	ui::openWindow();
	ui::config(settings);

	StateManager stateMan;
	stateMan.addState("IntroState");

	for (bool running = true; running == true;) {
		std::cout << "Loop" << std::endl;
		auto event = terminal_read();

		// Global close
		if (event == TK_CLOSE) {
			break;
		}
		
		stateMan.update(event);
		stateMan.draw();
	}

	ui::closeWindow();
	return 0;

}
