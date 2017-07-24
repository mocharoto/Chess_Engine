//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the pawn class.
#include <iostream>
#include <string>
#include "pieces.h"
#include "pawn.h"

using namespace std;

void Pawn::move(coord newPos, board::Square ** Chessboard)
{
	setPosition(newPos, Chessboard);

}

coordList Pawn::calculateMoves(coord boundary) const
{
	coordList validMoves;
	// Pawn can move in 4 directions left, right, down, and up by 1.
	if (position.x + 1 <= boundary.x) {
		validMoves.push_back(coord{position.x + 1, position.y});
	}
	if (position.x - 1 >= 0) {
		validMoves.push_back(coord{position.x - 1, position.y});
	}

	if (position.y + 1 <= boundary.y) {
		validMoves.push_back(coord{position.x, position.y + 1});
	}
	if (position.y - 1 >= 0) {
		validMoves.push_back(coord{position.x, position.y - 1});
	}
	return validMoves;
}

void Pawn::promote()
{
	string promotedPiece = "";
	if (position.y == 8)
	{
		std::cout << "What would you like to promote to? ";
		std::cin >> promotedPiece;
		if (promotedPiece == "Queen" || promotedPiece == "queen")
		{
			//Promote to Queen
			//New Queen
			//Queen newQueen = new Queen();
			//sets the position of the Queen
			//I don't know if this is the correct way.
			//newQueen->setPosition(this->getPosition(), tile);
			//Destroys the Pawn piece
			//I don't know if we have a destructor...
			//~:Pawn();

		}
		if (promotedPiece == "Rook" || promotedPiece == "rook")
		{
			//Promote to Rook
			//New Rook
			//Rook newRook = new Rook();
			//sets the position of the Rook
			//newRook->setPostion(this->getPosition(), tile);
			//Destroys Pawn
			//~:Pawn();
		}
		if (promotedPiece == "Knight" || promotedPiece == "knight")
		{
			//Promote to Knight
			//New Knight
			//Knight newKnight = new Knight();
			//sets the position of the Knight
			//newKnight->setPosition(this->getPostion(), tile);
			//Destroys the Pawn piece
			//~:Pawn();
		}
		if (promotedPiece == "Bishop" || promotedPiece == "bishop")
		{
			//Promote to Bishop
			//New Bishop
			//Bishop newBishop = new Bishop();
			//sets the position of the Bishop
			//newBishop->setPosition(this->getPosition(), tile);
			//Destroys the Pawn piece
			//~:Pawn();
		}
	}
}