#include "queen.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "king.h"
#include "defs.h"
#include "coord.h"

namespace PieceUtils
{
	inline std::shared_ptr<Pieces> pieceFromType(PieceType type, coord pos, TeamColor color)
	{
		std::shared_ptr<Pieces> newPiece;
		if (type == PieceType::Queen)
			newPiece = std::make_shared<Queen>(pos, color);
		else if (type == PieceType::King)
			newPiece = std::make_shared<King>(pos, color);
		else if (type == PieceType::Pawn)
			newPiece = std::make_shared<Pawn>(pos, color);
		else if (type == PieceType::Bishop)
			newPiece = std::make_shared<Bishop>(pos, color);
		else if (type == PieceType::Rook)
			newPiece = std::make_shared<Rook>(pos, color);
		else if (type == PieceType::Knight)
			newPiece = std::make_shared<Knight>(pos, color);

		return newPiece;
	}
}
