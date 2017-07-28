//Author: Julian Yi
//Date: 14 July 2017
//Header file for the board

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
/*
	structure of a square
	isOccupied will check if a piece is placed on the square
	canMove will determine if a piece can be moved here
	tag is the name of the given square
*/

#define sizeY 8
#define sizeX 8

class board
{
	private:


	public:
		struct Square {
			bool isOccupied;
			bool canMove;
			std::string tag;
			std::string pieceTag;
		};

		bool placePiece(std::string pieceName, int x, int y, board::Square **Chessboard);
		board::Square initializeBoard(board::Square **Chessboard);

		board()
		{

		}

};

#endif