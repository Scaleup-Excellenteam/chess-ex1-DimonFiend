#include "Pawn.h"
#include "PieceFactory.h"
#include "indexStruct.h"

bool Pawn::registerIt = PieceFactory::registerPiece("P", [](bool isWhite) -> std::unique_ptr<Piece> {
    return std::make_unique<Pawn>(isWhite);
    });

// Pawn movement:
// For simplicity, assume:
// - A pawn moves one step forward (direction depends on color).
// - It can move diagonally by one square for capturing.
bool Pawn::checkMoveRange(const indexPair& source, const indexPair& destination) const
{
    int rowDiff = destination.row - source.row;
    int colDiff = std::abs(destination.col - source.col);

    if (this->isWhite())
    {
        // White moves upward (assuming lower row index is forward).
        if (rowDiff == 1)
        {
            // Forward move.
            if (colDiff == 0)
                return true;
            // Diagonal (capture) move.
            if (colDiff == 1)
                return true;
        }
    }
    else
    {
        // Black moves downward (assuming higher row index is forward).
        if (rowDiff == -1)
        {
            // Forward move.
            if (colDiff == 0)
                return true;
            // Diagonal (capture) move.
            if (colDiff == 1)
                return true;
        }
    }
    return false;
}
