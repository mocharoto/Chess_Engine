//Author: Julian Yi
//Date Created: 7 August 2017
//File Description: c++ code for the king.
//Fun Fact: Simon Kim is now Simon King 
#include <iostream>
#include <string>
#include "king.h"

King::King(coord pos) : Pieces()
{
	type = PieceType::King;
	position = pos;
}

coordList calculateMoves(coord boundary, const squareGrid& square) const override
{
	
}
