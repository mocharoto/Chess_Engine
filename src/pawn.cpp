//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the pawn class.
#include <iostream>
#include <string>
#include "pieces.h"
#include "pawn.h"

using namespace std;

void Pawn::move(coord newPos)
{
	setPosition(newPos);

}

void Pawn::promote()
{
	//do things
}
