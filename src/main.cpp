//Author: Julian Yi
//Date Started: 14 July 2017, Friday.
//Purpose: This is a project to create a working chess engine and gui using C++.
//File: This is the main file.
#include <iostream>
#include <memory>
#include "board.h"
#include "pawn.h"
#include "knight.h"
#include "coord.h"



int main(){
	auto testPawn = new Pawn();
	testPawn->setPosition(coord{0, 3});
	std::cout << "Pawn at: " << testPawn->getPosition().x << " " << testPawn->getPosition().y << std::endl;

	coordList validMoves;

	validMoves = testPawn->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}

	auto testKnight = new Knight();
	testKnight->setPosition(coord{2, 3});
	std::cout << "Knight at: " << testKnight->getPosition().x << " " << testKnight->getPosition().y << std::endl;

	validMoves = testKnight->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}
	return 0;
}
