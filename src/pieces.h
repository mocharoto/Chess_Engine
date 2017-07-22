//Author: Julian Yi
//Date Created: 18 July 2016
//File Description: Header file for the pieces.

#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <string>
#include <vector>
#include "coord.h"

using coordList = std::vector<coord>;

class Pieces
{
	public:
		// Setters & Getters
		void setPieceColor(std::string newColor);
		std::string getPieceColor() const;
		void setPieceName(std::string newName);
		std::string getPieceName() const;
		void setPosition(coord newPos);
		coord getPosition() const;

		virtual void move(coord newPos) = 0;
		// Returns a list of all possible coordinates to move to.
		virtual coordList calculateMoves(coord boundary) const;
	protected:
		//std::string is not a ptr, you can't make them a null
		std::string pieceColor = "";
		std::string pieceName = "";
		coord position;
};

#endif
