#include "Rook.h"
#include "PieceFactory.h"

bool Rook::registerIt = PieceFactory::registerPiece("R", [](bool isWhite) -> std::unique_ptr<Piece>{ return std::make_unique<Rook>(isWhite); });