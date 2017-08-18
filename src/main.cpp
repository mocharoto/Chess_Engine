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
#include "statemanager.h"

void handleInput(board& Chessboard);

int main()
{
	terminal_open();
	//ui::openWindow();
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
	    "filter=[keyboard, mouse];";
	 //ui::config(settings);
	 std::cout << "Window setup" << std::endl;
	 StateManager stateMan;
	 std::string test;
	 std::cout << "Paused, please enter something:" << std::endl;
	 std::cin >> test;
	 stateMan.addState("IntroState");
	 for (bool running = true; running == true;) {
		 	auto event = terminal_read();
			stateMan.update(event);
			stateMan.draw();
			// exit if empty stateMan
	}

	/*
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

	ui::openWindow();

	// Font setup. ./font/FSEX300.ttf
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
	    "filter=[keyboard, mouse];";


	 ui::config(settings);

	// Print intro text.
	//terminal_print(1, 1, "Chess Engine");
	//terminal_print(4, 2, "by C");
	//terminal_print(1, 4, "Press Enter to start...");


	// Create UI manager
	ui UIManager;

	// Create title screen
	UIManager.addElement(
		std::make_shared<TitleElement>(
			"Chess Engine",
			"white",
			Alignment::Centered
		),
		{windowSize::x / 2, (windowSize::y / 2) - 5}
	);
	UIManager.addElement(
		std::make_shared<TitleElement>(
			"by Julian Yi, Sean Brock,",
			"grey",
			Alignment::Centered
		),
		{windowSize::x / 2, (windowSize::y / 2) - 3}
	);
	UIManager.addElement(
		std::make_shared<TitleElement>(
			"Simon Kim, and Consquigi", // hue
			"grey",
			Alignment::Centered
		),
		{windowSize::x / 2, (windowSize::y / 2) - 2}
	);
	UIManager.addElement(
		std::make_shared<TitleElement>(
			"Press Enter",
			"red",
			Alignment::Centered
		),
		{windowSize::x / 2, (windowSize::y / 2) + 1}
	);

	// Draw Initial Screen
	UIManager.draw();
	terminal_refresh();

	// Wait for Enter key press to continue.
	for (bool wait = true; wait;) {
		auto key = terminal_read();
		if (key == TK_ENTER)
			wait = false;
	}

	// Clear title screen and continue.
	UIManager.clear();

	// Set flag to prevent waiting for terminal_read on first loop.
	bool firstLoop = true;

	// Register the chessboard in a board element.
	coord boardPos;
	boardPos.x = (windowSize::x / 2) - (boardSize::x / 2);
	boardPos.y = (windowSize::y / 2) - (boardSize::y / 2);
	UIManager.addElement(std::make_shared<BoardElement>(Chessboard), { boardPos });

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
		auto key = TK_ENTER;
		if (firstLoop) {
			firstLoop = false;
		} else {
			key = terminal_read();
		}
		// Reset the terminal to blank state.
		terminal_clear();

		// Text goes on layer 3.
		terminal_layer(TerminalLayer::Messages);

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



		// Commit the buffer and draw it.
		// Move to ui manager eventually.
		terminal_refresh();

	}

	// We're done here.
	terminal_close();

	return 0;
	*/
}
