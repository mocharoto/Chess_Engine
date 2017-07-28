//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp file for Pieces
#include <iostream>
#include <string>
#include "pieces.h"
#include "board.h"

using namespace std;

Pieces::Pieces() : pieceColor(""), pieceName(""), position({0, 0}) { }

void Pieces::setPieceColor(string newColor)
{
	pieceColor = newColor;
}

string Pieces::getPieceColor() const
{
	return pieceColor;
}

void Pieces::setPieceName(string newName)
{
	pieceName = newName;
}

string Pieces::getPieceName() const
{
	return pieceName;
}

void Pieces::setPosition(coord newPos, board::Square ** Chessboard)
{
	bool canPlace = true;
	board thisBoard;
	canPlace = thisBoard.placePiece(pieceName, newPos.x, newPos.y, Chessboard);

	if (canPlace == true)
	{
		position = newPos;
		cout << pieceName << " is Placed at " << Chessboard[position.x][position.y].tag << endl;
	}
	else if(canPlace == false)
	{
		cout << "can't place a " << pieceName << " at " << Chessboard[newPos.x][newPos.y].tag << " " << Chessboard[newPos.x][newPos.y].pieceTag << " is there" << endl;
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
