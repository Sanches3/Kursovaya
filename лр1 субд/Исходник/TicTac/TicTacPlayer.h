#pragma once
#include "pch.h"
#include "TicTacBoard.h"

class TicTacPlayer
{
protected:
	TicTacBoard* board;
	CellType cellType;
	string name;
public:
	void SetupPlayer(string name, CellType cellType);
	void SetBoard(TicTacBoard* board);
	virtual bool MakeMove() = 0;
	string GetName();
};

