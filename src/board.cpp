//Author: Julian Yi
//Date: 14 July 2017
//board functions

#include <iostream>
#include "board.h"
#include "pieceutils.h"

board::board() : squares()
{ }

bool board::placePiece(PieceType piece, coord pos, TeamColor color)
{
	auto current = &squares[pos.x][pos.y];

	if (!current->occupied())
	{
		current->canMove = false;
		current->pieces.push_back(PieceUtils::pieceFromType(piece, pos));
		current->pieces.front()->team = color;
		
		std::cout << colorToString(color) << " " << pieceToString(piece) << " is Placed at (" << pos.x << ", " << pos.y << ")" << std::endl;
		
		return true;
	}
	else
	{
		std::cout << "unable to place Piece " << pieceToString(piece) << " at (" << pos.x << ", " << pos.y << "). "
				  << pieceToString(current->pieces.front()->type) << " is Occupying the space." << std::endl;

		return false;
	}
}

bool board::movePiece(coord oldPos, coord newPos)
{
	//  Input validation
	if (oldPos.x > boardSize::x || oldPos.x < 0) {
		std::cout << "Old position X out of bounds (0, " << boardSize::x << ")" << std::endl;
		return false;
	}
	if (oldPos.y > boardSize::y || oldPos.y < 0) {
		std::cout << "Old position Y out of bounds (0, " << boardSize::y << ")" << std::endl;
		return false;
	}
	if (newPos.x > boardSize::x || newPos.x < 0) {
		std::cout << "Old position X out of bounds (0, " << boardSize::x << ")" << std::endl;
		return false;
	}
	if (newPos.y > boardSize::y || newPos.y < 0) {
		std::cout << "Old position Y out of bounds (0, " << boardSize::y << ")" << std::endl;
		return false;
	}

	auto oldS = &squares[oldPos.x][oldPos.y];
	if (oldS->pieces.empty()) {
		std::cout << "No piece to move at (" << oldPos.x << ", " << oldPos.y << ")" << std::endl;
		return false;
	}

	auto newS = &squares[newPos.x][newPos.y];

	// Get the moves for the piece located in the old square
	auto availableMoves = oldS->pieces.front()->calculateMoves({boardSize::x, boardSize::y}, squares);
	if (availableMoves.empty()) {
		std::cout << "No available moves for (" << oldPos.x << ", " << oldPos.y << ")" << std::endl;
		return false;
	}
	/*
	for (auto move : availableMoves) {
		std::cout << "(" << move.x << ", " << move.y << ") ";
	}
	std::cout << std::endl;
	*/
	if (std::find(availableMoves.begin(), availableMoves.end(), newPos) != availableMoves.end()) {
		// move to newpos.
		std::cout << colorToString(oldS->pieces.front()->team) << " " << pieceToString(oldS->pieces.front()->type) << " Attempting to move to (" << newPos.x << ", " << newPos.y << ")" << std::endl;

		if (!newS->pieces.empty()) {
			if (newS->pieces.front()->team == oldS->pieces.front()->team) {
				 std::cout << "Friendly piece at (" << newPos.x << ", " << newPos.y << "), against the rules." << std::endl;
				 return false;
			}
			
			std::cout << "(" << newPos.x << ", " << newPos.y << ") " << "is occupied by " << colorToString(newS->pieces.front()->team) << " "  << pieceToString(newS->pieces.front()->type) << std::endl;
			std::cout << colorToString(newS->pieces.front()->team) << " " << pieceToString(newS->pieces.front()->type) << " destroyed at (" << newPos.x << ", " << newPos.y << ")" << std::endl;
			newS->pieces.clear();
		}


		newS->pieces.push_back(oldS->pieces.front());
		newS->pieces.front()->setPosition(newPos); //position needs to change to the new position otherwise the piece pointer will still have the old positions
		oldS->pieces.clear();

		/* made for testing purpose
			coord pos = newS->pieces.front()->getPosition(); 
			std::cout << pos.x << pos.y;
		*/
		std::cout << "Successful move. " << colorToString(newS->pieces.front()->team) << " " << pieceToString(newS->pieces.front()->type) << " was moved to (" << newPos.x << ", " << newPos.y << ")" << std::endl;
		

	} else {
		// Not in the move list.
		std::cout << "Cannot move to (" << newPos.x << ", " << newPos.y << "), against the rules." << std::endl;
		return false;
	}

	return true;
}

bool board::deletePiece(coord pos)
{
	auto current = &squares[pos.x][pos.y];
	if (current->occupied())
	{
		current->canMove = true;
		//don't change the boardTag
		current->pieces.pop_back();
		return true;
	}
	return false;
}

void board::initializeBoard()
{
	int Ascii = 65;
	std::string boardTag = "";

	for (int index = 0; index < boardSize::y; ++index)
	{
		for (int jindex = 0; jindex < boardSize::x; ++jindex)
		{
			boardTag = (char(Ascii));
			boardTag += std::to_string(jindex);
			auto current = &squares[index][jindex];
			current->canMove = true;
			//squares[index]->tag = (char(Ascii) + '-' + char(index));
			current->tag = boardTag;
		}
		Ascii++;
	}
}

PieceType board::getSquareType(coord pos) const
{
	if (squares[pos.x][pos.y].occupied()) {
		return squares[pos.x][pos.y].pieces.front()->type;
	}
	return PieceType::None;
}

TeamColor board::getSquareColor(coord pos) const
{
	if (squares[pos.x][pos.y].occupied()) {
		return squares[pos.x][pos.y].pieces.front()->team;
	}
	return TeamColor::None;
}

//created for testing purpose
void board::printBoard()
{
	for (int index = 0; index < boardSize::y; ++index)
	{
		for (int jindex = 0; jindex < boardSize::x; ++jindex)
		{
			std::cout << squares[index][jindex].tag;
		}

		std::cout << std::endl;
	}
}
