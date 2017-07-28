//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the pawn class.
#include <iostream>
#include <string>
#include "pieces.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "board.h"
#include "coord.h"

using namespace std;

Pawn::Pawn() : Pieces()
{
	pieceName = "Pawn";
	pieceColor = "White";
}

coordList Pawn::calculateMoves(coord boundary) const
{
	coordList validMoves;

	// Pawn can move in y direction away from its start.
	// The pawn can also only attack diagonally (not implemented).

	// Vertical move.
	if (pieceColor == "White") {
		if (position.y + 1 <= boundary.y) {
			validMoves.push_back(coord{position.x, position.y + 1});
			// Check diagonal via x direction. (Check for occupied enemy in future).
			if (position.x + 1 <= boundary.x) // && position.x + 1 occupied
				validMoves.push_back(coord{position.x + 1, position.y + 1});
			if (position.x - 1 <= boundary.x) // && position.x - 1 occupied
				validMoves.push_back(coord{position.x - 1, position.y + 1});
		}
	} else { // pieceColor == "Black"
		if (position.y - 1 >= 0) {
			validMoves.push_back(coord{position.x, position.y - 1});
			// Check diagonal via x direction. (Check for occupied enemy in future).
			if (position.x + 1 <= boundary.x) // && position.x + 1 occupied
				validMoves.push_back(coord{position.x + 1, position.y - 1});
			if (position.x - 1 <= boundary.x) // && position.x - 1 occupied
				validMoves.push_back(coord{position.x - 1, position.y - 1});
		}
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
