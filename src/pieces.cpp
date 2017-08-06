//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp file for Pieces
#include <iostream>
#include <string>
#include "pieces.h"
#include "board.h"
#include "pawn.h"
#include "defs.h"

using namespace std;

Pieces::Pieces() : team(TeamColor::None), type(PieceType::None), position({0, 0}) { }

void Pieces::setPosition(coord newPos)
{
	position = newPos;
}

coord Pieces::getPosition() const
{
	return position;
}

coordList Pieces::calculateMoves(coord boundary, const squareGrid& square) const
{
	coordList moveList;
	return moveList;
}
