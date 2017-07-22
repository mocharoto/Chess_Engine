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
	private:
	public:
		void move(coord newPos);
		coordList calculateMoves(coord boundary) const;
};

#endif
