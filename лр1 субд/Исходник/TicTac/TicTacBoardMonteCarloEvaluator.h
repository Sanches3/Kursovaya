#pragma once
#include "TicTacBoard.h"

class TicTacBoardMonteCarloEvaluator
{
private:
	TicTacBoard* board;
	int numGames;
	int numVictories;
	int numLosses;
	int numDraws;
	unsigned int col;
	CellType startCellType;

public:
	TicTacBoardMonteCarloEvaluator(TicTacBoard* board, int numIterations, CellType startCellType, unsigned int col);
	~TicTacBoardMonteCarloEvaluator();
	void EvaluateBoard();
	void Evaluate();
	int GetVictories() { return numVictories; }
	int GetLosses() { return numLosses; }
	int GetDraws() { return numDraws; }
	int GetColPos() { return col; }
};

