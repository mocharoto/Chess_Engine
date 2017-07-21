//Author: Julian Yi
//Date Created: 18 July 2016
//File Description: Header file for the pieces.
#pragma once
#include <iostream>
#include <string>

class Pieces
{
	protected:
		string pieceColor = 'NULL';
		string pieceName = 'NULL';
		int xCoordinate = 0;
		int yCoordinate = 0;
	public:
		void setPieceColor(string newColor);
		string getPieceColor();
		void setPieceName(string newName);
		string getPieceName();
		void setxCoordinate(int location);
		int getxCoordinate();
		void setyCoordinate(int location);
		int getyCoordinate();
		virtual void move(int newXLocation, int newYLocation) = 0;

} Pieces;
