//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp file for Pieces
#include <iostream>
#include <string>
#include "pieces.h"

using namespace std;

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

void Pieces::setPosition(coord newPos)
{
	position = newPos;
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
