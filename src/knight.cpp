//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp file for the Knight class
#include <iostream>
#include <string>
#include "knight.h"

Knight::Knight(coord pos, TeamColor color) : Pieces()
{
	type = PieceType::Knight;
	position = pos;
	team = color;
}

coordList Knight::calculateMoves(coord boundary, const squareGrid& square) const
{
	coordList validMoves;

	// Create a vector of coords representing the moves of a knight.
	// A knight can also move to the swapped form of these. (i.e. { 2, 1 })
	coordList moves = {
		{ 1, 2 }, { 1, -2 }, { -1, 2 }, { -1, -2 },
	};

	for (auto& move : moves) {
		// Check if the move is valid.
		if (position.x + move.x <= boundary.x && position.x + move.x <= boundary.x) {
			validMoves.push_back(position + move);
		}
		// Check if the swapped move is valid.
		if (position.x + move.y <= boundary.x && position.x + move.y <= boundary.x) {
			validMoves.push_back(position + move.swap());
		}
	}

	return validMoves;
}
