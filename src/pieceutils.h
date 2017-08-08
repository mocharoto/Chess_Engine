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
	inline std::shared_ptr<Pieces> pieceFromType(PieceType type, coord pos)
	{
		std::shared_ptr<Pieces> newPiece;
		if (type == PieceType::Queen)
			newPiece = std::make_shared<Queen>(pos);
		else if (type == PieceType::King)
			newPiece = std::make_shared<King>(pos);
		else if (type == PieceType::Pawn)
			newPiece = std::make_shared<Pawn>(pos);
		else if (type == PieceType::Bishop)
			newPiece = std::make_shared<Bishop>(pos);
		else if (type == PieceType::Rook)
			newPiece = std::make_shared<Rook>(pos);
		else if (type == PieceType::Knight)
			newPiece = std::make_shared<Knight>(pos);

		return newPiece;
	}
}