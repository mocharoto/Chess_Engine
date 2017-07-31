//Author: Julian Yi
//Date: 14 July 2017
//Header file for the board

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include "defs.h"
/*
	structure of a square
	isOccupied will check if a piece is placed on the square
	canMove will determine if a piece can be moved here
	tag is the name of the given square
*/

class board
{
	public:
		board();

		struct Square {
			bool isOccupied;
			bool canMove;
			std::string tag;
			PieceType pieceType;
		};

		bool placePiece(PieceType pieceType, int x, int y, board::Square **Chessboard);
		void deletePiece(int x, int y, board::Square **Chessboard);
		board::Square initializeBoard(board::Square **Chessboard);

		static constexpr int sizeY = 8;
		static constexpr int sizeX = 8;
};

#endif
