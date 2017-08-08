//Author: Julian Yi
//Date Created: 27 July 2017
//File Description: Header files for the King
#ifndef KING_H
#define KING_H

#include <iostream>
#include <string>
#include "pieces.h"

class King : public Pieces
{
	protected:
	public:
		King(coord pos);
		coordList calculateMove(coord boudary, const squareGrid& square) const override;
}

#endif

