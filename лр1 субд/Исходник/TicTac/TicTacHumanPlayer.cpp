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
	cout << "\n Игрок " << name << ",ваш ход...\n Введите столбец : ";
	cin >> col;
	if (this->board->CheckLegal(col))
	{
		this->board->SetCell(col, this->cellType);
		return true;
	}
	return false;
}