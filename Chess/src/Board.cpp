#include "Board.h"
#include "PieceFactory.h"

enum class PieceType
{
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING
};

Board::Board(const std::string& players)
{
	for (int row = 0; row < BOARD_SIZE; ++row)
	{
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			const char pieceChar = players[row * BOARD_SIZE + col];
			bool isWhite = std::isupper(pieceChar);
			m_Board[row][col] = std::move(PieceFactory::createPiece(std::string(1,pieceChar)));
		}
	}
}

int Board::checkAction(const std::string& action)
{
	std::cout << action + " Gavno" << std::endl;
	return 41;
}
