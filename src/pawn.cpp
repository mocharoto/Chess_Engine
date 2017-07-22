//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the pawn class.
#include <iostream>
#include <string>
#include "pieces.h"
#include "pawn.h"

using namespace std;

void Pawn::move(int newXCoordinate, int newYCoordinate)
{
	setxCoordinate(newXCoordinate);
	setyCoordinate(newYCoordinate);
}

void Pawn::promote()
{
	//do things
}
