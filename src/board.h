//Author: Julian Yi
//Date: 14 July 2017
//Header file for the board
#pragma once
#include <iostream>
#include "pieces.h"

/*
	structure of a square
	isOccupied will check if a piece is placed on the square
	canMove will determine if a piece can be moved here
	tag is the name of the given square
*/
struct Square {
	bool isOccupied;
	bool canMove;
	std::string tag;
};

struct Position {
	int x = 0;
	int y = 0;
};
