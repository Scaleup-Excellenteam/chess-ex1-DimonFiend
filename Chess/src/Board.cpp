#include "Board.h"
#include "PieceFactory.h"
#include "Utility.h"
#include "Piece.h"
#include "indexStruct.h"

enum class CodeType
{
	CT_NO_PAWN = 11,
	CT_ENEMY_PAWN = 12,
	CT_ALLY_PAWN = 13,
	CT_ILLEGAL_MOVE = 21,
	CT_CHECK_OWN = 31,
	CT_LEGAL_CHECK_MOVE = 41,
	CT_LEGAL_MOVE = 42,
};

Board::Board(const std::string& players)
	:m_isWhiteTurn(true)
{
	for (int row = 0; row < BOARD_SIZE; ++row)
	{
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			const char pieceChar = players[row * BOARD_SIZE + col];
			m_Board[row][col] = std::move(PieceFactory::createPiece(std::string(1,pieceChar)));
		}
	}
}

int Board::checkAction(const std::string& action)
{
	indexPair sourceIndex = { Utility::charToIntBoard(action[0]), Utility::stringToInt(action[1])};
	indexPair destIndex = { Utility::charToIntBoard(action[2]), Utility::stringToInt(action[3])};
	boardDebug();
	if (sourceIndex.row >= 0 && sourceIndex.col >= 0)
	{
		auto piece = getPiece(sourceIndex.row, sourceIndex.col);

		if (!piece)
		{
			return (int)CodeType::CT_NO_PAWN;
		}

		if (piece && (piece->isWhite() != m_isWhiteTurn))
		{
			return (int)CodeType::CT_ENEMY_PAWN;
		}

		bool validMove = piece->checkMoveRange(sourceIndex, destIndex);
		if(validMove)
		{
			m_isWhiteTurn = !m_isWhiteTurn;
			movePiece(sourceIndex, destIndex);
			return (int)CodeType::CT_LEGAL_MOVE;
		}
		else
		{
			return (int)CodeType::CT_ILLEGAL_MOVE;
		}
	}

	return (int)CodeType::CT_ILLEGAL_MOVE;
}

Piece* Board::getPiece(int row, int col) const
{
	return m_Board[row][col].get();
}

void Board::boardDebug()const
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (m_Board[i][j] == nullptr) std::cout << "# ";
			if (m_Board[i][j] != nullptr) std::cout << "X ";
		}
		std::cout << "\n";
	}
}

void Board::movePiece(indexPair source, indexPair destination)
{
	m_Board[destination.row][destination.col] = std::move(m_Board[source.row][source.col]);
	m_Board[source.row][source.col] = nullptr;
}