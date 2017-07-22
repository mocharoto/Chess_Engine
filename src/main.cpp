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
	test->setPosition(coord{1, 3});
	std::cout << "Pawn at: " << test->getPosition().x << " " << test->getPosition().y << std::endl;

	auto validMoves = test->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}
	return 0;
}
