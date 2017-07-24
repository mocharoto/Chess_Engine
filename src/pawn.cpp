//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the pawn class.
#include <iostream>
#include <string>
#include "pieces.h"
#include "pawn.h"

using namespace std;

void Pawn::move(coord newPos, board::Square ** Chessboard)
{
	setPosition(newPos, Chessboard);

}

coordList Pawn::calculateMoves(coord boundary) const
{
	coordList validMoves;
	// Pawn can move in 4 directions left, right, down, and up by 1.
	if (position.x + 1 <= boundary.x) {
		validMoves.push_back(coord{position.x + 1, position.y});
	}
	if (position.x - 1 >= 0) {
		validMoves.push_back(coord{position.x - 1, position.y});
	}

	if (position.y + 1 <= boundary.y) {
		validMoves.push_back(coord{position.x, position.y + 1});
	}
	if (position.y - 1 >= 0) {
		validMoves.push_back(coord{position.x, position.y - 1});
	}
	return validMoves;
}

void Pawn::promote()
{
	//do things
}
