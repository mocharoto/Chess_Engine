//Author: Julian Yi
//Date: 16 July 2017
//Definitions file

#ifndef DEFS_H
#define DEFS_H

#include <string>
#include <algorithm>
#include <string>


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
		result = 0x50; // P
	else if (type == PieceType::Knight)
		result = 0x4B;
	else if (type == PieceType::Rook)
		result = 0x52;
	else if (type == PieceType::Bishop)
		result = 0x42;
	else if (type == PieceType::Queen)
		result = 0x51;
	else if (type == PieceType::King)
		result = 0x4B;
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
		result = "grey";
	else {
		std::cout << "Error: colorToString returned None color." << std::endl;
		result = "None";
	}
	return result;
}

/*
enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };
enum { WHITE, BLACK, BOTH };
enum {
	A1 = 21, B1, C1, D1, E1, F1, G1, H1,
	A2 = 31, B2, C2, D2, E2, F2, G2, H2,
	A3 = 41, B3, C3, D3, E3, F3, G3, H3,
	A4 = 51, B4, C4, D4, E4, F4, G4, H4,
	A5 = 61, B5, C5, D5, E5, F5, G5, H5,
	A6 = 71, B6, C6, D6, E6, F6, G6, H6,
	A7 = 81, B7, C7, D7, E7, F7, G7, H7,
	A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE };
*/
#endif
