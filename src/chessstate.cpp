#include "chessstate.h"
#include "BearLibTerminal.h"

ChessState::ChessState() : State(), Chessboard() {
	// Initialize board.
	Chessboard = std::make_shared<board>();
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


	// Register the chessboard in a board element.
	/*
	coord boardPos;
	boardOffset.x = (windowSize::x / 2) - (boardSize::x / 2);
	boardOffset.y = (windowSize::y / 2) - (boardSize::y / 2);
	*/
	uiManager.addElement(std::make_shared<BoardElement>(Chessboard), { boardOffset });

}

StateChange ChessState::update(int event) {
	StateChange nextState;

	//std::cout << "Chess event handling: " << std::endl;
	switch (event) {
		case TK_ESCAPE:
			// Exit the game state.
			nextState.operation = StateChange::Operation::Pop;
			break;
		case TK_ENTER:
			break;
		case TK_MOUSE_MOVE:
			xCursor = terminal_state(TK_MOUSE_X);
			yCursor = terminal_state(TK_MOUSE_Y);
			std::cout << xCursor << "," << yCursor << std::endl;
			std::cout << boardOffset.x << "," << boardOffset.y << std::endl;
			break;
		case TK_MOUSE_LEFT:
			mouseClicks++; //amount of time something is clicked
			if ((boardOffset.x <= xCursor && xCursor <= (boardOffset.x + 7)) && (boardOffset.y <= yCursor && yCursor <= (boardOffset.y + 7))){
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
			break;
	}

	return nextState;
}

void ChessState::draw() {
	terminal_clear();

	uiManager.draw();

	//std::cout << "Cursor: " << std::to_string(xCursor) << " " << std::to_string(yCursor) << std::endl;
	if((boardOffset.x <= xCursor && xCursor <= (boardOffset.x + 7)) && (boardOffset.y <= yCursor && yCursor <= (boardOffset.y + 7)))
	{
		int select = 0x02C7;
		terminal_layer(TerminalLayer::PiecesSelect);
		terminal_color(color_from_name("green"));
		terminal_put(xCursor, yCursor, select);
	}

	terminal_refresh();
}
