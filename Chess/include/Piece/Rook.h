#pragma once
#include "Piece.h"

struct indexPair;
class Rook : public Piece
{
public:
	Rook(bool isWhite) : Piece(isWhite) {};
	virtual bool checkMoveRange(const indexPair& source, const indexPair& destination) const override;
	
private:
	static bool registerIt;
};