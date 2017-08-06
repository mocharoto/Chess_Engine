//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: Header File for the Knight Class

#ifndef KNIGHT_H
#define KNIGHT_H

#include "pieces.h"
#include <iostream>
#include <string>

class Knight : public Pieces
{
	public:
		Knight(coord pos);

		coordList calculateMoves(coord boundary, const squareGrid& square) const override;
};

#endif
