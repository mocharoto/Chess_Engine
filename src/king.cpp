//Author: Julian Yi
//Date Created: 7 August 2017
//File Description: c++ code for the king.
//Fun Fact: Simon Kim is now Simon King
#include <iostream>
#include <string>
#include "king.h"

King::King(coord pos, TeamColor color) : Pieces()
{
	type = PieceType::King;
	position = pos;
	team = color;
}

coordList King::calculateMoves(coord boundary, const squareGrid& square) const
{
	coordList validMoves;
	
	coordList moves = 
	{
		//Diagonal unit vectors
		{ 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1},
		//Orthogonal unit vectors
		{ 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
	};

	for ( auto& move : moves )
	{
		coord newPos = position + move;
		//Loop each direction to adjacent sqaure.
		if((newPos.x < boundary.y && newPos.y < boundary.y) && (newPos.x >= 0 && newPos.y >=0))
		{
			if(!square[newPos.x][newPos.y].occupied())
			{
				validMoves.push_back(newPos);
				newPos = newPos + move;
			}
			else
			{
				if(square[newPos.x][newPos.y].pieces.front()->getTeamColor() != team)
				{
					validMoves.push_back(newPos);
				}
			}
		}

	}	



	return validMoves;

}
