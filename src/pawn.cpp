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

Pawn::Pawn() : Pieces()
{
	pieceName = "Pawn";
	pieceColor = "White";
}

coordList Pawn::calculateMoves(coord boundary) const
{
	coordList validMoves;

	// Pawn can move in y direction away from its start.
	// The pawn can also only attack diagonally (not implemented).

	// Vertical move.
	if (pieceColor == "White") {
		if (position.y + 1 <= boundary.y) {
			validMoves.push_back(coord{position.x, position.y + 1});
			// Check diagonal via x direction. (Check for occupied enemy in future).
			if (position.x + 1 <= boundary.x) // && position.x + 1 occupied
				validMoves.push_back(coord{position.x + 1, position.y + 1});
			if (position.x - 1 <= boundary.x) // && position.x - 1 occupied
				validMoves.push_back(coord{position.x - 1, position.y + 1});
		}
	} else { // pieceColor == "Black"
		if (position.y - 1 >= 0) {
			validMoves.push_back(coord{position.x, position.y - 1});
			// Check diagonal via x direction. (Check for occupied enemy in future).
			if (position.x + 1 <= boundary.x) // && position.x + 1 occupied
				validMoves.push_back(coord{position.x + 1, position.y - 1});
			if (position.x - 1 <= boundary.x) // && position.x - 1 occupied
				validMoves.push_back(coord{position.x - 1, position.y - 1});
		}
	}
	return validMoves;
}


//remember that index starts from 0 and ends at 7, so when we create 8x8 chessboard end point is 7,7 not 8,8
//TO DO:: make the promote function trigger when you set the pawn's y position to 7 (or 0 depending on color) 
Pieces* Pawn::promote(string Command, coord Position, board::Square ** tile, Pieces * thisPiece)
{
	Pieces *returnValue = this;

	//this erases the original pawn object
	delete thisPiece;
	
	//and it will replace it with the promoted pieces.
	if (Command.compare("Queen") == 0)
	{
		cout << "Promoting a Pawn to " << Command << endl;
		board tempBoard;
		tempBoard.deletePiece(Position.x, Position.y, tile);

		//create a new Queen object
		//I will follow along with your stupid joke Sean
		auto kylee = new Queen();

		kylee->setPosition(Position, tile, kylee);
		tempBoard.placePiece("Queen", Position.x, Position.y, tile);

		returnValue = kylee;
	}
	else if (Command.compare("Bishop") == 0)
	{
		cout << "Promoting a Pawn to " << Command << endl;
		board tempBoard;
		tempBoard.deletePiece(Position.x, Position.y, tile);

		//create a new Bishop object
		//I will follow along with your stupid joke Sean
		auto testBishop = new Bishop();

		testBishop->setPosition(Position, tile, testBishop);
		tempBoard.placePiece("Bishop", Position.x, Position.y, tile);

		returnValue = testBishop;
	}
	else if (Command.compare("Rook") == 0)
	{
		cout << "Promoting a Pawn to " << Command << endl;
		board tempBoard;
		tempBoard.deletePiece(Position.x, Position.y, tile);

		//create a new Queen object
		//I will follow along with your stupid joke Sean
		auto testRook = new Rook();

		testRook->setPosition(Position, tile, testRook);
		tempBoard.placePiece("Rook", Position.x, Position.y, tile);

		returnValue = testRook;
	}
	else if (Command.compare("Knight") == 0)
	{
		cout << "Promoting a Pawn to " << Command << endl;
		board tempBoard;
		tempBoard.deletePiece(Position.x, Position.y, tile);

		//create a new Queen object
		//I will follow along with your stupid joke Sean
		auto testKnight = new Knight();

		testKnight->setPosition(Position, tile, testKnight);
		tempBoard.placePiece("Knight", Position.x, Position.y, tile);

		returnValue = testKnight;
	}
	else
	{
		cout << "Not a correct Command" << endl;
	}


	return returnValue;
	//string promotedPiece = "";
	/*
	if (position.y == 8)
	{	
		
			std::cout << "What would you like to promote to? ";
			std::cin >> promotedPiece;
		
		if (promotedPiece == "Queen" || promotedPiece == "queen")
		{
			//Promote to Queen
			//New Queen
			//Queen newQueen = new Queen();
			//sets the position of the Queen
			//I don't know if this is the correct way.
			//newQueen->setPosition(this->getPosition(), tile);
			//Destroys the Pawn piece
			//I don't know if we have a destructor...
			//~:Pawn();

		}
		if (promotedPiece == "Rook" || promotedPiece == "rook")
		{
			//Promote to Rook
			//New Rook
			//Rook newRook = new Rook();
			//sets the position of the Rook
			//newRook->setPostion(this->getPosition(), tile);
			//Destroys Pawn
			//~:Pawn();
		}
		if (promotedPiece == "Knight" || promotedPiece == "knight")
		{
			//Promote to Knight
			//New Knight
			//Knight newKnight = new Knight();
			//sets the position of the Knight
			//newKnight->setPosition(this->getPostion(), tile);
			//Destroys the Pawn piece
			//~:Pawn();
		}
		if (promotedPiece == "Bishop" || promotedPiece == "bishop")
		{
			//Promote to Bishop
			//New Bishop
			//Bishop newBishop = new Bishop();
			//sets the position of the Bishop
			//newBishop->setPosition(this->getPosition(), tile);
			//Destroys the Pawn piece
			//~:Pawn();
		}
	}
	*/
}
