//Author: Julian Yi
//Date Started: 14 July 2017, Friday.
//Purpose: This is a project to create a working chess engine and gui using C++.
//File: This is the main file.
#include <iostream>
#include "board.h"
#include "pieces.h"



int main(void)
{

	Pieces *test = nullptr;
	test->setyCoordinate(1);
	test->setxCoordinate(3);
	std::cout << test->getxCoordinate() << " " << test->getyCoordinate() << std::endl;
	return 0;
}