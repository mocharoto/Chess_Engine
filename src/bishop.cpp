//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the Bishop class
#include <iostream>
#include <string>
#include "pieces.h"
#include "bishop.h"

void Bishop::move(coord newPos, board::Square ** Chessboard)
{
	setPosition(newPos, Chessboard);
	//TO DO:
	//Make rules to only allow Bishops to move in a diagonal.
}
