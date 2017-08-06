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
#include "defs.h"

class Pieces
{
	public:
		Pieces();

		void setPosition(coord newPos);
		coord getPosition() const;

		// Returns a list of all possible coordinates to move to.
		virtual coordList calculateMoves(coord boundary, squareGrid &square) const;

		TeamColor team;
		PieceType type;

	protected:
		coord position;
};

#endif
