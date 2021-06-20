#pragma once
#include "CellType.h"

class TicTacBoard
{
private:
	unsigned int boardline;
	unsigned int boardcolumn;
	CellType** cells;
	bool bVictory = false;
	bool isRowMade(unsigned int row);
	bool isColMade(unsigned int col);
	bool isDiagMade();
	bool isBoardFull();
public:
	TicTacBoard(unsigned int line, unsigned int column);
	TicTacBoard(TicTacBoard* board);
	virtual ~TicTacBoard();
	void Show();
	void SetCell(unsigned int column, CellType ct);
	bool CheckLegal(unsigned int column);
	bool CheckEndCondition();
	bool isVictory();
};

