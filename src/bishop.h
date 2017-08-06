//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: Header file for Bishop class

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include <string>
#include "pieces.h"

class Bishop : public Pieces
{
	public:
		Bishop(coord pos);

		coordList calculateMoves(coord boundary, const squareGrid& square) const override;
};

#endif
