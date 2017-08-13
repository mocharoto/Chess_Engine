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
#include "ui.h"
#include "BearLibTerminal.h"

void handleInput(board& Chessboard);

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

	Chessboard->placePiece(PieceType::Pawn, { 2,3 }, TeamColor::Black);


	Chessboard->movePiece({ 1,1 }, { 1,2 }); //success
	Chessboard->movePiece({ 1,2 }, { 2,3 }); //success
	Chessboard->movePiece({ 2,3 }, { 3,3 }); //fail

	Chessboard->placePiece(PieceType::Pawn, { 3,4 }, TeamColor::Black);
	Chessboard->movePiece({ 3,4 }, { 2,3 }); //success

	Chessboard->placePiece(PieceType::Pawn, { 1,2 }, TeamColor::White);
	Chessboard->movePiece({ 2,3 }, { 1,2 });
	//Chessboard->movePiece({ 1,2 }, { 0,1 });
	//Chessboard->movePiece({ 0,1 }, { 1,0 });
	//Chessboard->movePiece({ 1,1 }, { 1,0 });


	/*
	it all works
	// Test an attack.
	// Expected Output : success, knight is destroyed
	Chessboard->movePiece({3, 4}, {1, 2});

	// Test creating a piece into the occupied coordinate (same color)
	// Expected Output : failure
	Chessboard->placePiece(PieceType::Rook, { 3,3 }, TeamColor::White);
	Chessboard->placePiece(PieceType::Pawn, { 3,3 }, TeamColor::White);

	// Test creating a piece into the occupied coordinate (different color)
	// Expected Output : failure
	Chessboard->deletePiece({ 3,3 });
	Chessboard->placePiece(PieceType::Pawn, { 3,3 }, TeamColor::White);
	Chessboard->placePiece(PieceType::Bishop, { 3,3 }, TeamColor::Black);

	// Test Moving a piece into the occupied coordinate (same color)
	// Expected Output : failure
	Chessboard->placePiece(PieceType::Pawn, { 3,2 }, TeamColor::White);
	Chessboard->movePiece({ 3,2 }, { 3,3 });
	*/

	// Test Pawn's valid moves

	// Open the terminal. Since no terminal_set() method is called,
	// the terminal will use default settings.
	ui::openWindow();

	// Font setup. ./font/FSEX300.ttf
	std::string settings =
		"window:"
			"title='Chess',"
			"size='46x24';"
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
	    "filter=[keyboard, mouse];";

ui::config(settings);

	// Print intro text.
	terminal_print(1, 1, "Chess Engine");
	terminal_print(4, 2, "by Julian Yi, Sean Brock, and Simon Kim");
	terminal_print(1, 4, "Press Enter to start...");
	terminal_refresh();

	// Create UI manager
	ui UIManager;
	// Register the chessboard in a board element.
	UIManager.addElement(std::make_shared<boardElement>(Chessboard), { 2, 5 });

	//roughdraft until I figure out a better way to do this
	int mouseClicks = 0;
	int xCursor = 0;
	int yCursor = 0;
	coord current = {0, 0};
	coord next = {0, 0};
	bool clicked = false;

	bool running = true;
	coord boardOffset{ 2, 5 };

	while (running) {
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
				break;
			case TK_MOUSE_MOVE:
				xCursor = terminal_state(TK_MOUSE_X);
		 		yCursor = terminal_state(TK_MOUSE_Y);
				break;
			case TK_MOUSE_LEFT:
				mouseClicks++; //amount of time something is clicked

				if ((2 <= xCursor && xCursor <= 9) && (5 <= yCursor && yCursor <= 12)){
				//if the clicked square has something then set the object clicked flag to true and set the current coordinate
					if (Chessboard->occupied({ (xCursor - boardOffset.x), (yCursor - boardOffset.y) }) == true && (mouseClicks == 1))
					{
						current = { (xCursor - boardOffset.x), (yCursor - boardOffset.y) };
						std::cout << "first click" << current.x << "," << current.y << std::endl;
						clicked = true;
						std::cout << mouseClicks;
					}
					//if clicked flag is false and there is nothing on the board don't do anything
					else if(Chessboard->occupied({ (xCursor - boardOffset.x), (yCursor - boardOffset.y) }) == false && clicked == false)
					{
						current = { -1, -1 };
						std::cout << "nothing was clicked" << std::endl;
						mouseClicks = 0;
					}
					//mouseClicks has to be higher than 1 to perform the move function. clicked flag also has to be true
					//handles move
					if(clicked == true && mouseClicks > 1)
					{
						//do something with that piece
						next = {(xCursor - boardOffset.x), (yCursor - boardOffset.y)};
						std::cout << "second click" << next.x << "," << next.y << std::endl;
						Chessboard->movePiece(current, next);
						clicked = false;
						std::cout << mouseClicks;
						mouseClicks = 0;
					}
				}
				break;
			default:
				terminal_print(1, 2, "The key pressed has no function.");
				break;
		}

		// Draw board
		UIManager.draw();

		if((2 <= xCursor && xCursor <=9) && (5 <= yCursor && yCursor <= 12))
		{
			int select = 0x02C7;
			terminal_layer(2);
			terminal_color(color_from_name("green"));
			terminal_put(xCursor, yCursor, select);
		}

			 	//TK_MOUSE_CLICK
		//set the flag
		//flag true then call something.
		/*
		if (key == TK_MOUSE_LEFT)
		{
			int mouseClicks = terminal_state(TK_MOUSE_LEFT);
			if(mouseClicks == 1)
			{
				//select the piece
				current = {(xCursor - boardOffset.x), (yCursor - boardOffset.y)};
				std::cout << "first click" << current.x << "," << current.y << std::endl;
			}
			else if(mouseClicks == 2)
			{
				//do something with that piece
				next = {(xCursor - boardOffset.x), (yCursor - boardOffset.y)};
				std::cout << "second click" << next.x << "," << next.y << std::endl;
				Chessboard->movePiece(current, next);
			}
		}
		*/


		// Commit the buffer and draw it.
		// Move to ui manager eventually.
		terminal_refresh();

	}

	// We're done here.
	terminal_close();

	return 0;
}
