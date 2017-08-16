#include "element.h"
#include "defs.h"
#include "BearLibTerminal.h"

void BoardElement::draw(coord pos) {
	coord boardOffset = pos;

	// Draw the board background.

	terminal_layer(TerminalLayer::Board);

	int checker = 0x2588; // Unicode character for a full tile.
	for (int y = 0; y < boardSize::y; y++) {
		//int checker = 0xB7; // Unicode for a centered dot.
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

	// Draw the pieces.
	terminal_layer(1);
	for (int y = 0; y < boardSize::y; y++) {
		for (int x = 0; x < boardSize::x; x++) {
			auto currentType = boardRef->getSquareType({x, y});
			if (currentType != PieceType::None) {
				std::string pieceColor = colorToDraw( boardRef->getSquareColor({x,y}) );
				//std::cout << "Color: " << pieceColor.c_str() << std::endl;
				terminal_color( color_from_name(pieceColor.c_str()) );
				terminal_put( boardOffset.x + x, boardOffset.y + y, pieceDrawCode(currentType) );
			}
		}
	}
}

void TitleElement::draw(coord pos) {
	// Default alignement is to the left.
	coord alignedPos = pos;

	if (align == Alignment::Right) {
		// Move to left the message length +2 to account for end characters.
		alignedPos.x = pos.x + 2 - message.length();
	} else if (align == Alignment::Centered) {
		// Move left half of the message length.
		alignedPos.x = pos.x - int(message.length() / 2);
	}

	terminal_color(color_from_name(color.c_str()));
	terminal_print(alignedPos.x, alignedPos.y, message.c_str());
}
