#pragma once
#include <iostream>

struct indexPair;
class Board;
class Piece
{
public:
	Piece(bool isWhite) : m_isWhite(isWhite) {};
	virtual ~Piece() = default;

	virtual bool checkMoveRange(const indexPair& source, const indexPair& destination, const Board& board) const = 0;
	virtual bool isKing() const { return false; };
	const bool isWhite() const { return m_isWhite; };

private:
	bool m_isWhite;
};