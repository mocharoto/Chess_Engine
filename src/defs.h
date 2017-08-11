//Author: Julian Yi
//Date: 16 July 2017
//Definitions file

#ifndef DEFS_H
#define DEFS_H

#include <string>
#include <algorithm>
#include <string>
#include <iostream>


enum class PieceType
{
	Pawn,
	Knight,
	Rook,
	Bishop,
	Queen,
	King,
	None
};

inline PieceType pieceFromString(std::string pieceStr)
{
	PieceType result;

	// Make the input string all lowercase.
	std::transform(pieceStr.begin(), pieceStr.end(), pieceStr.begin(), ::tolower);

	if (pieceStr == "pawn")
		result = PieceType::Pawn;
	else if (pieceStr == "knight")
		result = PieceType::Knight;
	else if (pieceStr == "rook")
		result = PieceType::Rook;
	else if (pieceStr == "bishop")
		result = PieceType::Bishop;
	else if (pieceStr == "queen")
		result = PieceType::Queen;
	else if (pieceStr == "king")
		result = PieceType::King;
	else
		result = PieceType::None;

	return result;
}

inline std::string pieceToString(PieceType type)
{
	std::string result;

	if (type == PieceType::Pawn)
		result = "Pawn";
	else if (type == PieceType::Knight)
		result = "Knight";
	else if (type == PieceType::Rook)
		result = "Rook";
	else if (type == PieceType::Bishop)
		result = "Bishop";
	else if (type == PieceType::Queen)
		result = "Queen";
	else if (type == PieceType::King)
		result = "King";
	else
		result = "None";

	return result;
}

inline int pieceDrawCode(PieceType type)
{
	int result;

	if (type == PieceType::Pawn)
		result = 0x2659; // P
	else if (type == PieceType::Knight)
		result = 0x2658;
	else if (type == PieceType::Rook)
		result = 0x2656;
	else if (type == PieceType::Bishop)
		result = 0x2657;
	else if (type == PieceType::Queen)
		result = 0x2655;
	else if (type == PieceType::King)
		result = 0x2654;
	else if (type == PieceType::None)
		result = 0xAD;
	else
		result = 0x40;

	return result;
}

enum class TeamColor
{
	White,
	Black,
	None
};

inline TeamColor colorFromString(std::string colorStr)
{
	TeamColor result;

	// Make the input string all lowercase.
	std::transform(colorStr.begin(), colorStr.end(), colorStr.begin(), ::tolower);

	if (colorStr== "white")
		result = TeamColor::White;
	else if (colorStr == "black")
			result = TeamColor::Black;
	else
		result = TeamColor::None;

	return result;
}

inline std::string colorToString(TeamColor color)
{
	std::string result;

	if (color == TeamColor::White)
		result = "white";
	else if (color == TeamColor::Black)
		result = "black";
	else {
		std::cout << "Error: colorToString returned None color." << std::endl;
		result = "None";
	}
	return result;
}

inline std::string colorToDraw(TeamColor color)
{
	std::string result;

	if (color == TeamColor::White)
		result = "whitepiece";
	else if (color == TeamColor::Black)
		result = "blackpiece";
	else {
		std::cout << "Error: colorToDraw returned None color." << std::endl;
		result = "red";
	}
	return result;
}

#endif
