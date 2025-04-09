#pragma once
#include <array>
#include <memory>
#include "Piece.h"
#include <string>

struct indexPair;
constexpr int BOARD_SIZE = 8;

class Board {
public:
	Board(const std::string& players);
	int checkAction(const std::string& action);
	void boardDebug() const;
private:
	std::array<std::array<std::unique_ptr<Piece>, BOARD_SIZE>, BOARD_SIZE> m_Board;
	void movePiece(indexPair source, indexPair destination);
	Piece* getPiece(int row, int col) const;

	bool m_isWhiteTurn;
};