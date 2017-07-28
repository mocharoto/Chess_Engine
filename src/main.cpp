//Author: Julian Yi
//Date Started: 14 July 2017, Friday.
//Purpose: This is a project to create a working chess engine and gui using C++.
//File: This is the main file.
#include <iostream>
#include <memory>
#include "board.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "coord.h"

#define sizeY 8
#define sizeX 8

int main()
{
	board Chessboard;
	board::Square **tile = new board::Square*[sizeY];

	for (int index = 0; index < sizeY; ++index)
	{
		tile[index] = new board::Square[sizeX];
	}

	Chessboard.initializeBoard(tile);

	auto testPawn = new Pawn();
	testPawn->setPosition(coord{0, 3}, tile);
	std::cout << testPawn->getPieceName() << " " << testPawn->getPosition().x << " " << testPawn->getPosition().y << std::endl;

	coordList validMoves;

	validMoves = testPawn->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}

	auto testKnight = new Knight();
	testKnight->setPosition(coord{0, 3}, tile);
	std::cout << "Knight at: " << testKnight->getPosition().x << " " << testKnight->getPosition().y << std::endl;

	validMoves = testKnight->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}

	auto testBishop = new Bishop();
	testBishop->setPosition(coord{2, 2}, tile);
	std::cout << "Bishop at: " << testBishop->getPosition().x << " " << testBishop->getPosition().y << std::endl;

	validMoves = testBishop->calculateMoves(coord{10, 10});
	for (auto& move : validMoves) {
		std::cout << "Can move to: " << move.x << " " << move.y << std::endl;
	}
	//Chessboard.placePiece("Pawn1", testPawn->getPosition().x, testPawn->getPosition().y, tile);
	//Chessboard.placePiece("Knight1", testPawn->getPosition().x, testPawn->getPosition().y, tile);

	std::cout << "pause here" << std::endl;


	for (int index = 0; index < sizeY; ++index)
	{
		delete[] tile[index];
	}

	delete[] tile;



	return 0;
}
