#pragma once
#include <array>
#include <memory>
#include "Piece.h"
#include <string>

constexpr int BOARD_SIZE = 8;

class Board {
public:
	Board(const std::string& players);
	int checkAction(const std::string& action);
private:
	std::array<std::array<std::unique_ptr<Piece>, BOARD_SIZE>, BOARD_SIZE> m_Board;
};