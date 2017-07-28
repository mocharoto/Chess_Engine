//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the Bishop class
#include <iostream>
#include <string>
#include "bishop.h"

Bishop::Bishop() : Pieces()
{
	pieceName = "Bishop";
	pieceColor = "White";
}

coordList Bishop::calculateMoves(coord boundary) const
{
	coordList validMoves;

	// Create a vector of coords representing the moves of a bishop.
	// The bishop can move in the diagonal directions.
	coordList moves = {
		{ 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 },
	};

	for (auto& move : moves) {
		coord newPos = position + move;

		// Loop each direction to the edge of the map.
		while((newPos.x <= boundary.x && newPos.y <= boundary.y) && (newPos.x >= 0 && newPos.y >= 0)) {
			validMoves.push_back(newPos);
			newPos = newPos + move;
		}
	}

	return validMoves;
}

void calculateByCast(coordList& coords, coord boundary)
{

}
