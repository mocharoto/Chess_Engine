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

void handleInput(board& Chessboard);

int main()
{
	board Chessboard;

	Chessboard.initializeBoard();

	for (int i = 0; i < 8; i++) {
		Chessboard.placePiece(PieceType::Pawn, {i, 1}, TeamColor::White);
	}

	Chessboard.placePiece(PieceType::Rook, {0, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Rook, {7, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Knight, {1, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Knight, {6, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Bishop, {2, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Bishop, {5, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::Queen, {3, 0}, TeamColor::White);
	Chessboard.placePiece(PieceType::King, { 4,0 }, TeamColor::White);

	for (int i = 0; i < 8; i++) {
		Chessboard.placePiece(PieceType::Pawn, {i, 6}, TeamColor::Black);
	}
	Chessboard.placePiece(PieceType::Rook, {0, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Rook, {7, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Knight, {1, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Knight, {6, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Bishop, {2, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Bishop, {5, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::Queen, {3, 7}, TeamColor::Black);
	Chessboard.placePiece(PieceType::King, { 4,7 }, TeamColor::Black);

	Chessboard.placePiece(PieceType::Pawn, { 2,3 }, TeamColor::Black);


	Chessboard.movePiece({ 1,1 }, { 1,2 }); //success
	Chessboard.movePiece({ 1,2 }, { 2,3 }); //success
	Chessboard.movePiece({ 2,3 }, { 3,3 }); //fail

	Chessboard.placePiece(PieceType::Pawn, { 3,4 }, TeamColor::Black);
	Chessboard.movePiece({ 3,4 }, { 2,3 }); //success

	Chessboard.placePiece(PieceType::Pawn, { 1,2 }, TeamColor::White);
	Chessboard.movePiece({ 2,3 }, { 1,2 });
	//Chessboard.movePiece({ 1,2 }, { 0,1 });
	//Chessboard.movePiece({ 0,1 }, { 1,0 });
	//Chessboard.movePiece({ 1,1 }, { 1,0 });


	/*
	it all works
	// Test an attack.
	// Expected Output : success, knight is destroyed
	Chessboard.movePiece({3, 4}, {1, 2});

	// Test creating a piece into the occupied coordinate (same color)
	// Expected Output : failure
	Chessboard.placePiece(PieceType::Rook, { 3,3 }, TeamColor::White);
	Chessboard.placePiece(PieceType::Pawn, { 3,3 }, TeamColor::White);

	// Test creating a piece into the occupied coordinate (different color)
	// Expected Output : failure
	Chessboard.deletePiece({ 3,3 });
	Chessboard.placePiece(PieceType::Pawn, { 3,3 }, TeamColor::White);
	Chessboard.placePiece(PieceType::Bishop, { 3,3 }, TeamColor::Black);

	// Test Moving a piece into the occupied coordinate (same color)
	// Expected Output : failure
	Chessboard.placePiece(PieceType::Pawn, { 3,2 }, TeamColor::White);
	Chessboard.movePiece({ 3,2 }, { 3,3 });
	*/

	// Test Pawn's valid moves





	// Open the terminal. Since no terminal_set() method is called,
	// the terminal will use default settings.
	terminal_open();

	// Font setup.
	terminal_set("window: title='Chess', size='46x24'; font: ./font/FSEX300.ttf, size=32x32");

	// Palette.
	terminal_set("palette: whitepiece=#C2CCCF, blackpiece=#4D483C, whitetile=#02171F, blacktile=#000000;");
	// Print intro text.
	terminal_print(1, 1, "Chess Engine");
	terminal_print(4, 2, "by Julian Yi, Sean Brock, and Simon Kim");
	terminal_print(1, 4, "Press Enter to start...");
	terminal_refresh();

	bool running = true;
	coord boardOffset{ 2, 5 };

	while (running) {
		bool drawBoard = false;
		bool drawPieces = false;

		// Check for input. termnial_read() is blocking, meaning the
		// program will wait until it reads a key press.
		auto key = terminal_read();

		// Reset the terminal to blank state.
		terminal_clear();

		// Text goes on layer 3.
		terminal_layer(3);

		// Print instructions.
		//terminal_print(1, 1, "Press Enter to start...");

		// Handle key presses.
		switch (key) {
			case TK_CLOSE:
				running = false;
				break;
			case TK_ESCAPE:
				running = false;
				break;
			case TK_ENTER:
				drawBoard = true;
				drawPieces = true;
				break;
			default:
				terminal_print(1, 2, "The key pressed has no function.");
				break;
		}


		// Draw the board background.
		if (drawBoard) {
			terminal_layer(0);
			int checker = 0x2588; // Unicode character for a full tile.
			//int checker = 0xB7; // Unicode for a centered dot.
			for (int y = 0; y < boardSize::y; y++) {
				for (int x = 0; x < boardSize::x; x++) {
					/*
					Checkerboard pattern can be made by (y % 2) XNOR (x % 2). XNOR is the same as ==
				  	/ 0 1 2 3
					0 B W B W
					1 W B W B
					2 B W B W
					For example, (0,0) is 0 XNOR 0 = 1, or easier to read 0 == 0 = 1. So (0,0) is black.
					*/
					std::string tileColor = y % 2 == x % 2 ? "blacktile" : "whitetile";
					terminal_color( color_from_name(tileColor.c_str()) );
					terminal_put(boardOffset.x + x, boardOffset.y + y, checker);
				}
			}
		}


		// Draw the pieces.
		if (drawPieces) {
			terminal_layer(1);
			for (int y = 0; y < boardSize::y; y++) {
				for (int x = 0; x < boardSize::x; x++) {
					auto currentType = Chessboard.getSquareType({x, y});
					if (currentType != PieceType::None) {
						std::string pieceColor = colorToDraw( Chessboard.getSquareColor({x,y}) );
						std::cout << "Color: " << pieceColor.c_str() << std::endl;
						terminal_color( color_from_name(pieceColor.c_str()) );
						terminal_put( boardOffset.x + x, boardOffset.y + y, pieceDrawCode(currentType) );
					}
				}
			}
		}

		// Commit the buffer and draw it.
		terminal_refresh();

	}

	// We're done here.
	terminal_close();

	return 0;
}
