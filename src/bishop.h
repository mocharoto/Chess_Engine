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
	private:
	public:
		void move(coord newPos);
		coordList calculateMoves(coord boundary) const;
};

#endif
