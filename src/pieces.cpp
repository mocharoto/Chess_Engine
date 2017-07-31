//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp file for Pieces
#include <iostream>
#include <string>
#include "pieces.h"
#include "board.h"
#include "pawn.h"
#include "defs.h"

using namespace std;

Pieces::Pieces() : team(TeamColor::None), type(PieceType::None), position({0, 0}) { }

void Pieces::setPosition(coord newPos, board::Square ** Chessboard)
{
	bool canPlace = true;
	board thisBoard;
	canPlace = thisBoard.placePiece(type, newPos.x, newPos.y, Chessboard);

	if (canPlace == true)
	{
		position = newPos;
		cout << pieceToString(type) << " is Placed at " << Chessboard[position.x][position.y].tag << endl;
	}
	else if(canPlace == false)
	{
		cout << "can't place a " << pieceToString(type) << " at " << Chessboard[newPos.x][newPos.y].tag << " " << pieceToString(Chessboard[newPos.x][newPos.y].pieceType) << " is there" << endl;
	}

	//if a piece named Pawn gets placed in position 8 or 0 call promote function
	if(type == PieceType::Pawn && (newPos.y == 7 || newPos.y == 0))
	{
		Pawn callthis;

		string Command = "";

		cout << "Pawn reached the promotion area, choose one of the options (Queen, Bishop, Rook, Knight)" << endl;
		cin >> Command;

		callthis.promote(Command, newPos, Chessboard, this);
	}
}

coord Pieces::getPosition() const
{
	return position;
}

coordList Pieces::calculateMoves(coord boundary) const
{
	coordList moveList;
	return moveList;
}
