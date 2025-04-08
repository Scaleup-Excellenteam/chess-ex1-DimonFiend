#pragma once
#include <iostream>

class Piece
{
public:
	Piece(bool isWhite) : m_isWhite(isWhite) {};
	 void test() const {
		std::cout << "Piece test" << std::endl;
	};

	 const bool isWhite() const { return m_isWhite; };

private:
	bool m_isWhite;
};