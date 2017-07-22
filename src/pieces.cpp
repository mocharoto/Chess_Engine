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

string Pieces::getPieceColor()
{
	return pieceColor;
}

void Pieces::setPieceName(string newName)
{
	pieceName = newName;
}

string Pieces::getPieceName()
{
	return pieceName;
}

void Pieces::setxCoordinate(int location)
{
	xCoordinate = location;
}

int Pieces::getxCoordinate()
{
	return xCoordinate;
}

void Pieces::setyCoordinate(int location)
{
	yCoordinate = location;
}

int Pieces::getyCoordinate()
{
	return yCoordinate;
}
