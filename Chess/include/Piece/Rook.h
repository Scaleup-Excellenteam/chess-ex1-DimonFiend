#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(bool isWhite) : Piece(isWhite) {};

private:
	static bool registerIt;
};