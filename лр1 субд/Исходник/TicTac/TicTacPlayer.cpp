#include "TicTacPlayer.h"

void TicTacPlayer::SetupPlayer(string name, CellType cellType)
{
	this->name = name;
	this->cellType = cellType;
}

void TicTacPlayer::SetBoard(TicTacBoard* board)
{
	this->board = board;
}

string TicTacPlayer::GetName()
{
	return this->name;
}
