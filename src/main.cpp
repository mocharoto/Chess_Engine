//Author: Julian Yi
//Date Started: 14 July 2017, Friday.
//Purpose: This is a project to create a working chess engine and gui using C++.
//File: This is the main file.
#include <iostream>
#include <memory>
#include "board.h"
#include "pawn.h"
#include "coord.h"



int main(){
	auto test = new Pawn();
	test->setyCoordinate(1);
	test->setxCoordinate(3);
	std::cout << test->getxCoordinate() << " " << test->getyCoordinate() << std::endl;

	coord c;
	std::cout << "Coord: x: " << c.x << ", y: " << c.y << std::endl;
	return 0;
}
