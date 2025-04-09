#include "King.h"
#include "PieceFactory.h"
#include "indexStruct.h"

bool King::registerIt = PieceFactory::registerPiece("K", [](bool isWhite) -> std::unique_ptr<Piece> { return std::make_unique<King>(isWhite); });

// Rooks moves in straight lines, either horizontally or vertically.
bool King::checkMoveRange(const indexPair& source, const indexPair& destination) const
{
	if(source.row == destination.row && source.col == destination.col)
		return false;

	if (source.row == destination.row && source.col == destination.col)
		return false;

	if (source.row == destination.row && source.col == destination.col)
		return false;

	if (source.row == destination.row && source.col == destination.col)
		return false;

	if (source.row == destination.row && source.col == destination.col)
		return false;

	if (source.row == destination.row && source.col == destination.col)
		return false;

	if (source.row == destination.row && source.col == destination.col)
		return false;

	if (source.row == destination.row && source.col == destination.col)
		return false;
}
