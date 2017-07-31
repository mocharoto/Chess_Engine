//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp file for Pieces
#include <iostream>
#include <string>
#include "pieces.h"
#include "board.h"
#include "pawn.h"

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

void Pieces::setPosition(coord newPos, board::Square ** Chessboard, Pieces * thisPiece)
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

	//if a piece named Pawn gets placed in position 8 or 0 call promote function 
	if(pieceName.compare("Pawn") == 0 && (newPos.y == 7 || newPos.y == 0))
	{
		Pawn callthis;

		string Command = "";

		cout << "Pawn reached the promotion area, choose one of the options (Queen, Bishop, Rook, Knight)" << endl;
		cin >> Command;

		callthis.promote(Command, newPos, Chessboard, thisPiece);
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
