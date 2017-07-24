//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: Header file for the pawn class.

#ifndef PAWN_H
#define PAWN_H

#include "pieces.h"

class Pawn : public Pieces
{
	public:
		void move(coord newPos, board::Square ** Chessboard);
		coordList calculateMoves(coord boundary) const;
		void promote();
		Pawn()
		{
			pieceName = "Pawn";
			pieceColor = "White";
			position.x = 0;
			position.y = 0;
		}
};

#endif
