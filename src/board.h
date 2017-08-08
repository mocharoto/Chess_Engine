//Author: Julian Yi
//Date: 14 July 2017
//Header file for the board

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <array>
#include <memory>
#include "defs.h"
#include "coord.h"
/*
	structure of a square
	isOccupied will check if a piece is placed on the square
	canMove will determine if a piece can be moved here
	tag is the name of the given square
*/

class Pieces;

struct Square {
	bool canMove = true;
	std::string tag = "";
	std::vector< std::shared_ptr<Pieces> > pieces;
	bool occupied() const {
		return !pieces.empty();
	}
};

namespace boardSize
{
	static constexpr int y = 8;
	static constexpr int x = 8;
}

using squareGrid = std::array<std::array<Square, boardSize::y>, boardSize::x>;

class board
{
	public:
		board();

		// Game play methods.
		bool movePiece(coord oldPos, coord newPos);
		bool placePiece(PieceType pieceType, coord pos, TeamColor color);
		bool deletePiece(coord pos);

		// Startup.
		void initializeBoard();

		// Debug.
		void printBoard();

		// Squares access for drawing
		PieceType getSquareType(coord pos) const;
		TeamColor getSquareColor(coord pos) const;

	private:
		void promote(coord pos, TeamColor color);
		squareGrid squares;
};

#endif
