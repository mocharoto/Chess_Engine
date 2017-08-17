//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: Header file for the pawn class.

#ifndef PAWN_H
#define PAWN_H

#include "pieces.h"

class Pawn : public Pieces
{
	public:
		Pawn(coord pos, TeamColor color);
		coordList calculateMoves(coord boundary, const squareGrid& square) const override;
		bool doubleMove = false;
};

#endif
