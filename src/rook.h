//Author: Julian Yi
//Date Created: 22 July 2017
//File Description:Header file for Rook

#include "pieces.h"

class Rook : public Pieces
{
	public:
		Rook();

		coordList calculateMoves(coord boundary) const;
};
