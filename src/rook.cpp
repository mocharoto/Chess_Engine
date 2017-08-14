//Author: Julian Yi
//Date Created: 22 July 2017
//File Description: .cpp file for the Rook
#include <iostream>
#include <string>
#include "rook.h"

Rook::Rook(coord pos, TeamColor color) : Pieces()
{
	type = PieceType::Rook;
	position = pos;
	team = color;
}

coordList Rook::calculateMoves(coord boundary, const squareGrid& square) const
{
	coordList validMoves;

	// Create a vector of coords representing the moves of a rook.
	// The rook can move orthogonally.
	coordList moves = {
    { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 },
	};

	for (auto& move : moves) {
		coord newPos = position + move;

		// Loop each direction to the edge of the map.
		while((newPos.x < boundary.x && newPos.y < boundary.y) && (newPos.x >= 0 && newPos.y >= 0)) {
			if (!square[newPos.x][newPos.y].occupied()){
				validMoves.push_back(newPos);
				newPos = newPos + move;
			}
			else {
				if(square[newPos.x][newPos.y].pieces.front()->getTeamColor() != team){
					validMoves.push_back(newPos);
				}
				break;
			}
		}
	}

	return validMoves;
}
