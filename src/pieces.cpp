//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp file for Pieces
#include <iostream>
#include <string>
#include "pieces.h"

using namespace std;

void setPieceColor(string newColor)
{
	pieceColor = newColor;
}

string getPieceColor()
{
	return pieceColor;
}

void setPieceName(string newName)
{
	pieceName = newName;
}

string getPieceName()
{
	return pieceName;
}

void setxCoordinate(int location)
{
	xCoordinate = location;
}

int getxCoordinate()
{
	return xCoordinate;
}

void setyCoordinate(int location)
{
	yCoordinate = location;
}

int getyCoordinate()
{
	return yCoordinate;
}
