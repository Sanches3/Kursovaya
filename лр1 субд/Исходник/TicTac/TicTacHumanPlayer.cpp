#include "TicTacHumanPlayer.h"

TicTacHumanPlayer::TicTacHumanPlayer()
{

}

TicTacHumanPlayer::~TicTacHumanPlayer()
{

}

bool TicTacHumanPlayer::MakeMove()
{
	unsigned int col;
	cout << "\n ����� " << name << ",��� ���...\n ������� ������� : ";
	cin >> col;
	if (this->board->CheckLegal(col))
	{
		this->board->SetCell(col, this->cellType);
		return true;
	}
	return false;
}