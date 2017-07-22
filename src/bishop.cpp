//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the Bishop class
#include <iostream>
#include <string>
#include "pieces.h"
#include "bishop.h"

void Bishop::move(int newXCoordinate, int newYCoordinate)
{
	setxCoordinate(newXCoordinate);
	setyCoordinate(newYCoordinate);
	//TO DO:
	//Make rules to only allow Bishops to move in a diagonal.
}
