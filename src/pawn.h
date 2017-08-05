//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: Header file for the pawn class.

#ifndef PAWN_H
#define PAWN_H

#include "pieces.h"

class Pawn : public Pieces
{
	public:
		Pawn(coord pos);

		coordList calculateMoves(coord boundary) const;
		//void promote(std::string Command, coord Position,);
};

#endif
