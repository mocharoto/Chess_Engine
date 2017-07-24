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
		void move(coord newPos, board::Square ** Chessboard);
		Bishop()
		{
			pieceName = "Bishop";
			pieceColor = "White";
			position.x = 0;
			position.y = 0;
		}
};

#endif
