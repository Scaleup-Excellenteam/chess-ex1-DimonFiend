#include "Queen.h"
#include "PieceFactory.h"
#include "indexStruct.h"

bool Queen::registerIt = PieceFactory::registerPiece("Q", [](bool isWhite) -> std::unique_ptr<Piece> {
    return std::make_unique<Queen>(isWhite);
    });

// The Queen moves like both a Rook and a Bishop.
bool Queen::checkMoveRange(const indexPair& source, const indexPair& destination) const
{
    int rowDiff = std::abs(source.row - destination.row);
    int colDiff = std::abs(source.col - destination.col);
    // Rook-like move: same row or same column.
    bool rookMove = (source.row == destination.row || source.col == destination.col);
    // Bishop-like move: diagonal movement.
    bool bishopMove = (rowDiff == colDiff && rowDiff != 0);
    return rookMove || bishopMove;
}
