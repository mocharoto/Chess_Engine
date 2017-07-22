//Author: Julian Yi
//Date Created: 18 July 2016
//File Description: Header file for the pieces.

#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <string>

class Pieces
{
	public:
		void setPieceColor(std::string newColor);
		std::string getPieceColor();
		void setPieceName(std::string newName);
		std::string getPieceName();
		void setxCoordinate(int location);
		int getxCoordinate();
		void setyCoordinate(int location);
		int getyCoordinate();
		virtual void move(int newXLocation, int newYLocation) = 0;
	protected:
		//std::string is not a ptr, you can't make them a null
		std::string pieceColor = "";
		std::string pieceName = "";
		int xCoordinate = 0;
		int yCoordinate = 0;
};

#endif