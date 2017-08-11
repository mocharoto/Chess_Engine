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

Pawn::Pawn(coord pos, TeamColor color) : Pieces()
{
	type = PieceType::Pawn;
	position = pos;
	team = color;
}

coordList Pawn::calculateMoves(coord boundary, const squareGrid& square) const
{
	coordList validMoves;


	// (Chessboard.getSquareColor(coord{ position.x + 1, position.y + 1 }) == TeamColor::Black

	// Pawn can move in y direction away from its start.
	// The pawn can also only attack diagonally (not implemented).

	// Vertical move.
	if (team == TeamColor::White) {
		if (position.y + 1 <= boundary.y)
		{
			// only move when there are no pieces in front no need to check for team here.
			if ((square[position.x][position.y + 1].occupied() == false))
			{
				validMoves.push_back(coord{ position.x, position.y + 1 });
			}
			// Check diagonal via x direction. (Check for occupied enemy in future).
			if ((position.x + 1 <= boundary.x) && (square[position.x + 1][position.y + 1].occupied() == true)) //(position.x + 1 <= boundary.x) &&   position.x + 1 occupied
			{
				//no need to check for the color of the occupying piece since it's going to be checked at the move function.
				validMoves.push_back(coord{ position.x + 1, position.y + 1 });
			}
			if ((position.x - 1 <= boundary.x) && (square[position.x - 1][position.y + 1].occupied() == true)) //(position.x - 1 <= boundary.x) &&  && position.x - 1 occupied
			{
				validMoves.push_back(coord{ position.x - 1, position.y + 1 });
			}
		}
	}
	else if (team == TeamColor::Black) {
		if (position.y - 1 >= 0)
		{
			// only move when there are no pieces in front no need to check for team here.
			if ((square[position.x][position.y - 1].occupied() == false))
			{
				validMoves.push_back(coord{ position.x, position.y - 1 });
			}
			// Check diagonal via x direction. (Check for occupied enemy in future).
			if ((position.x + 1 <= boundary.x) && (square[position.x + 1][position.y - 1].occupied() == true)) // && position.x + 1 occupied
			{
				validMoves.push_back(coord{position.x + 1, position.y - 1});
			}
			if ((position.x - 1 <= boundary.x) && (square[position.x - 1][position.y - 1].occupied() == true)) // && position.x - 1 occupied
			{
				validMoves.push_back(coord{ position.x - 1, position.y - 1 });
			}
		}
	} else {
		std::cout << "Error: Pawn team unset in calculateMoves." << std::endl;
	}
	return validMoves;
}


//remember that index starts from 0 and ends at 7, so when we create 8x8 chessboard end point is 7,7 not 8,8
//TODO: make the promote function trigger when you set the pawn's y position to 7 (or 0 depending on color)
/*
Pieces* Pawn::promote(string Command, coord Position, board::Square ** tile, Pieces * thisPiece)
{
	//this erases the original pawn object
	delete thisPiece;

	//and it will replace it with the promoted pieces.
	cout << "Promoting a Pawn to " << Command << endl;
	board tempBoard;
	Pieces* promotedPiece;
	PieceType newType = pieceFromString(Command);
	tempBoard.deletePiece(Position.x, Position.y, tile);

	switch(newType)
	{
		case PieceType::Queen:
			//create a new Queen object
			//I will follow along with your stupid joke Sean
			promotedPiece = new Queen();
			break;
		case PieceType::Bishop:
			//create a new Bishop object
			promotedPiece = new Bishop();
			break;
		case PieceType::Rook:
			//create a new Queen object
			promotedPiece = new Rook();
			break;
		case PieceType::Knight:
			//create a new Queen object
			//I will follow along with your stupid joke Sean
			promotedPiece = new Knight();
			break;
		default:
			promotedPiece = new Pawn();
			cout << "Not a correct Command" << endl;
			break;
	};

	promotedPiece->setPosition(Position, tile);
	tempBoard.placePiece(newType, Position.x, Position.y, tile);

	return promotedPiece;
}
*/
