#pragma once
#include <iostream>

struct indexPair;
class Piece
{
public:
	Piece(bool isWhite) : m_isWhite(isWhite) {};

	virtual bool checkMoveRange(const indexPair& source, const indexPair& destination) const = 0;
	const bool isWhite() const { return m_isWhite; };

private:
	bool m_isWhite;
};