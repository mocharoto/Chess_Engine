//Author: Julian Yi
//Date Created: 22 July 2017
//File Description: Header file for the Queen
//Fun Fact: Simon's queen is Kylee Lattomus

#include "pieces.h"

class Queen : public Pieces
{
	public:
		Queen(coord pos);

		coordList calculateMoves(coord boundary) const;
};
