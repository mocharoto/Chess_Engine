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
#include "board.h"
#include "coord.h"

using namespace std;

Pawn::Pawn(coord pos, TeamColor color) : Pieces()
{
	type = PieceType::Pawn;
	position = pos;
	team = color;
}

coordList Pawn::calculateMoves(coord boundary, const squareGrid& square) const
{
	// List of possible
	coordList validMoves;


	// Vertical move.
	if (team == TeamColor::White) {
		if (position.y + 1 < boundary.y)
		{
			// only move when there are no pieces in front no need to check for team here.
			if (position.y == 1)
			{
				if((square[position.x][position.y + 1].occupied == false) && (square[position.x][position.y + 2].occupied == false))
					validMoves.push_back(coord{ position.x, position.y + 2 });
			}
			if ((square[position.x][position.y + 1].occupied() == false))
			{
				validMoves.push_back(coord{ position.x, position.y + 1 });
			}
			// Check diagonal via x direction. (Check for occupied enemy in future).
			if ((position.x + 1 < boundary.x) && (square[position.x + 1][position.y + 1].occupied() == true)) //(position.x + 1 <= boundary.x) &&   position.x + 1 occupied
			{
				//no need to check for the color of the occupying piece since it's going to be checked at the move function.
				validMoves.push_back(coord{ position.x + 1, position.y + 1 });
			}
			if ((position.x - 1 >= 0) && (square[position.x - 1][position.y + 1].occupied() == true)) //(position.x - 1 <= boundary.x) &&  && position.x - 1 occupied
			{
				validMoves.push_back(coord{ position.x - 1, position.y + 1 });
			}
			//checks the squares adjacent to the pawn on the fifth row of the board.
			/*if (position.y == 4)
			{
				if ((position.x + 1 < boundary.x) && square[position.x + 1][position.y + 1].occupied() == false && square[position.x + 1][4].pieces.front()->getTeamColor() == TeamColor::Black && square[position.x + 1][4].pieces.front()->getPieceType() == PieceType::Pawn )
				{
					if (square[position.x + 1][4].pieces.front()->getDoubleMove() == true)
					{
						validMoves.push_back(coord{ position.x + 1, position.y + 1 })
					}
				}
			}*/
		}
	}
	else if (team == TeamColor::Black) {
		if (position.y - 1 >= 0)
		{
			if (position.y == 6)
			{
				validMoves.push_back(coord{ position.x, position.y - 2 });
			}
			// only move when there are no pieces in front no need to check for team here.
			if ((square[position.x][position.y - 1].occupied() == false))
			{
				validMoves.push_back(coord{ position.x, position.y - 1 });
			}
			// Check diagonal via x direction. (Check for occupied enemy in future).
			if ((position.x + 1 < boundary.x) && (square[position.x + 1][position.y - 1].occupied() == true)) // && position.x + 1 occupied
			{
				validMoves.push_back(coord{position.x + 1, position.y - 1});
			}
			if ((position.x - 1 >= 0) && (square[position.x - 1][position.y - 1].occupied() == true)) // && position.x - 1 occupied
			{
				validMoves.push_back(coord{ position.x - 1, position.y - 1 });
			}
		}
	} else {
		std::cout << "Error: Pawn team unset in calculateMoves." << std::endl;
	}

	return validMoves;
}

bool Pawn::getDoubleMove() 
	return doubleMove;
{
}

void Pawn::setDoubleMove(bool newDoubleMove)
{
	doubleMove = newDoubleMove;
}
