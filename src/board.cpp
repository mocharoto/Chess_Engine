//Author: Julian Yi
//Date: 14 July 2017
//board functions

#include <iostream>
#include "board.h"
#include "pieceutils.h"

board::board() : squares()
{ }

/*void board::updateAttacks(coord pos, TeamColor color)
{


}*/

void board::promote(coord pos, TeamColor color)
{
	auto current = &squares[pos.x][pos.y];

	std::string Command = "";

	std::cout << colorToString(current->pieces.front()->getTeamColor()) << " Pawn has reached a promotion area Pick a type: ";
	std::cin >> Command;
	PieceType newType = pieceFromString(Command);

	deletePiece(pos);

	std::cout << "You picked " << Command << std::endl;

	placePiece(newType, pos, color);

}

bool board::placePiece(PieceType piece, coord pos, TeamColor color)
{
	auto current = &squares[pos.x][pos.y];

	if (!current->occupied())
	{
		current->pieces.push_back(PieceUtils::pieceFromType(piece, pos, color));

		std::cout << colorToString(color) << " " << pieceToString(piece) << " is Placed at (" << pos.x << ", " << pos.y << ")" << std::endl;

		return true;
	}
	else
	{
		std::cout << "unable to place Piece " << pieceToString(piece) << " at (" << pos.x << ", " << pos.y << "). "
				  << pieceToString(current->pieces.front()->getPieceType()) << " is Occupying the space." << std::endl;

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
	if (oldPos ==  newPos) {
		std::cout << "Not Valid both same items " << std::endl;
		return false;
	}

	//Check if there is a piece
	auto oldS = &squares[oldPos.x][oldPos.y];
	if (oldS->pieces.empty()) {
		std::cout << "No piece to move at (" << oldPos.x << ", " << oldPos.y << ")" << std::endl;
		return false;
	}

	// Get the moves for the piece located in the old square
	auto newS = &squares[newPos.x][newPos.y];
	auto availableMoves = oldS->pieces.front()->calculateMoves({boardSize::x, boardSize::y}, squares);
	if (availableMoves.empty()) {
		std::cout << "No available moves for (" << oldPos.x << ", " << oldPos.y << ")" << std::endl;
		return false;
	}

	// Find if the new move is in the availableMoves
	if (std::find(availableMoves.begin(), availableMoves.end(), newPos) != availableMoves.end()) {
		std::cout << colorToString(oldS->pieces.front()->getTeamColor()) << " " << pieceToString(oldS->pieces.front()->getPieceType()) << " Attempting to move to (" << newPos.x << ", " << newPos.y << ")" << std::endl;

		if (!newS->pieces.empty()) {

			//NOT requried for final. All pieces have this in them
			if (newS->pieces.front()->getTeamColor() == oldS->pieces.front()->getTeamColor()) {
				 std::cout << "Friendly piece at (" << newPos.x << ", " << newPos.y << "), against the rules." << std::endl;
				 return false;
			}

			std::cout << "(" << newPos.x << ", " << newPos.y << ") " << "is occupied by " << colorToString(newS->pieces.front()->getTeamColor()) << " "  << pieceToString(newS->pieces.front()->getPieceType()) << std::endl;
			std::cout << colorToString(newS->pieces.front()->getTeamColor()) << " " << pieceToString(newS->pieces.front()->getPieceType()) << " destroyed by " << colorToString(oldS->pieces.front()->getTeamColor()) << " " << pieceToString(oldS->pieces.front()->getPieceType()) << " at (" << newPos.x << ", " << newPos.y << ")" << std::endl;

			//Delete the current piece in the square
			newS->pieces.clear();
		}


		newS->pieces.push_back(oldS->pieces.front());
		newS->pieces.front()->setPosition(newPos); //position needs to change to the new position otherwise the piece pointer will still have the old positions
		oldS->pieces.clear();

		/* made for testing purpose
			coord pos = newS->pieces.front()->getPosition();
			std::cout << pos.x << pos.y;
		*/
		std::cout << "Successful move. " << colorToString(newS->pieces.front()->getTeamColor()) << " " << pieceToString(newS->pieces.front()->getPieceType()) << " was moved to (" << newPos.x << ", " << newPos.y << ")" << std::endl;
		newS->pieces.front()->increaseMove();
		std::cout << "Move Counter is " << newS->pieces.front()->getMove() << std::endl;
		/*
			call promote if a Pawn Piece type reaches a y coordinate of 0 or 7 depending on their color
		*/
		if (newS->pieces.front()->getPieceType() == PieceType::Pawn)
		{
			if (newS->pieces.front()->getTeamColor() == TeamColor::White && newPos.y == 7)
			{
				promote(newPos, TeamColor::White);
			}
			else if (newS->pieces.front()->getTeamColor() == TeamColor::Black && newPos.y == 0)
			{
				promote(newPos, TeamColor::Black);
			}
		}
		/*
			calls en passant if a pawn double jumps and another pawn is right next to it.
		*/



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
			//squares[index]->tag = (char(Ascii) + '-' + char(index));
			current->tag = boardTag;
		}
		Ascii++;
	}
}

bool board::occupied(coord pos)
{
	return squares[pos.x][pos.y].occupied();
}

PieceType board::getSquareType(coord pos) const
{
	if (squares[pos.x][pos.y].occupied()) {
		return squares[pos.x][pos.y].pieces.front()->getPieceType();
	}
	return PieceType::None;
}

TeamColor board::getSquareColor(coord pos) const
{
	if (squares[pos.x][pos.y].occupied()) {
		return squares[pos.x][pos.y].pieces.front()->getTeamColor();
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
