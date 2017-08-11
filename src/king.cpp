//Author: Julian Yi
//Date Created: 7 August 2017
//File Description: c++ code for the king.
//Fun Fact: Simon Kim is now Simon King
#include <iostream>
#include <string>
#include "king.h"

King::King(coord pos, TeamColor color) : Pieces()
{
	type = PieceType::King;
	position = pos;
	team = color;
}

coordList King::calculateMoves(coord boundary, const squareGrid& square) const
{
	coordList validMoves;

	// Create a vector of coords representing the moves of a king.
	// The king can move diagonally and orthogonally.
	coordList moves = {
		// Diagonal unit vectors.
		{ 1, 1 },{ 1, -1 },{ -1, 1 },{ -1, -1 },
		// Orthogonal unit vectors.
		{ 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },
	};

	for (auto& move : moves)
	{
		coord newPos = position + move;

		validMoves.push_back(newPos);
	}




	return validMoves;

}
