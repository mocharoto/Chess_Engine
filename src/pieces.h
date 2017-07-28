//Author: Julian Yi
//Date Created: 18 July 2016
//File Description: Header file for the pieces.

#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <string>
#include <vector>

#include "coord.h"
#include "board.h"

class Pieces
{
	public:
		Pieces();

		// Setters & Getters
		void setPieceColor(std::string newColor);
		std::string getPieceColor() const;
		void setPieceName(std::string newName);
		std::string getPieceName() const;
		void setPosition(coord newPos, board::Square ** Chessboard);
		coord getPosition() const;

		// Returns a list of all possible coordinates to move to.
		virtual coordList calculateMoves(coord boundary) const;
	protected:
		std::string pieceColor;
		std::string pieceName;
		coord position;
};

#endif
