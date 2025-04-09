#pragma once
#include "Piece.h"

struct indexPair;
class King : public Piece
{
public:
	King(bool isWhite) : Piece(isWhite) {};
	virtual bool checkMoveRange(const indexPair& source, const indexPair& destination) const override;

private:
	static bool registerIt;
};