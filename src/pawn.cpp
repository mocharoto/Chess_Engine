//Author: Julian Yi
//Date Created: 18 July 2017
//File Description: .cpp for the pawn class.
#include <iostream>
#include <string>
#include "pieces.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"

using namespace std;

void Pawn::move(coord newPos)
{
	setPosition(newPos);

}

coordList Pawn::calculateMoves(coord boundary) const
{
	coordList validMoves;
	// Pawn can move in 4 directions left, right, down, and up by 1.
	if (position.x + 1 <= boundary.x) {
		validMoves.push_back(coord{position.x + 1, position.y});
	}
	if (position.x - 1 >= 0) {
		validMoves.push_back(coord{position.x - 1, position.y});
	}

	if (position.y + 1 <= boundary.y) {
		validMoves.push_back(coord{position.x, position.y + 1});
	}
	if (position.y - 1 >= 0) {
		validMoves.push_back(coord{position.x, position.y - 1});
	}
	return validMoves;
}

void Pawn::promote()
{
	//to do
	//check y coordinate
	//if y coordinate == 8
	//then piece should be promoted
	//in order for that to happen, the pawn object must be destroyed
	//and then it should be replaced with the promoted piece object. 
	string promotedPiece = "";

	if (position.y == 8)
	{
		std::cout << "Promote pawn to: ";
		std::cin >> promotedPiece;
		if(promotedPiece == "Queen" || promotedPiece == "queen")
		{
			//create queen object
			//give queen pawn's coordinates
			//destroy pawn
		}
		if(promotedPiece == "Rook" || promotedPiece == "rook")
		{
			//create rook object
			//give rook pawn's coordinates
			//destroy pawn
		}
		if(promotedPiece == "Bishop" || promotedPiece == "bishop")
		{
			//create bishop object
			//give bishop pawn's coordinates
			//destroy pawn
		}
		if(promotedPiece == "Knight" || promotedPiece == "knight")
		{
			//create knight object
			//give knight pawn's coordinates
			//destroy pawn
		}
	}
}
