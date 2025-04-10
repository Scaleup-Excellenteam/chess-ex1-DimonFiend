#pragma once
#include <array>
#include <memory>
#include "Piece.h"
#include <string>
#include "indexStruct.h"

constexpr int BOARD_SIZE = 8;

struct MoveIndices {
	indexPair source;
	indexPair destination;
};

class Board {
public:
	Board(const std::string& players);
	int validateAndPerformAction(const std::string& action);
	void boardDebug() const;
private:
	std::array<std::array<std::unique_ptr<Piece>, BOARD_SIZE>, BOARD_SIZE> m_Board;
	void initializeKing(int row, int col);
	MoveIndices parseAction(const std::string& action) const;

	void movePiece(indexPair source, indexPair destination);
	Piece* getPiece(indexPair index) const;

	std::unique_ptr<Piece> simulateMove(indexPair source, indexPair destination);
	void undoMove(indexPair source, indexPair destination, std::unique_ptr<Piece>& capturedPiece);

	indexPair findKingPosition(bool isWhite) const;
	bool isKingInCheck(bool isWhite) const;

	bool m_isWhiteTurn;

	Piece* m_whiteKing;
	Piece* m_blackKing;
	indexPair m_whiteKingPos;
	indexPair m_blackKingPos;
};