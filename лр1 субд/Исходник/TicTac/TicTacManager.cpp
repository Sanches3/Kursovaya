#include "TicTacManager.h"
#include "TicTacPlayer.h"
#include "TicTacHumanPlayer.h"
#include "TicTacComputerPlayer.h"

TicTacManager::TicTacManager()
{
	string playerName;
	int playerType;
	this->board = new TicTacBoard(8, 7);
	cout << " Введите тип игрока #1 (1 - Человек, любое другое число - Компьютер) : ";
	cin >> playerType;
	if (playerType == 1)
		this->player1 = new TicTacHumanPlayer();
	else
		this->player1 = new TicTacComputerPlayer();
	cout << " Введите тип игрока #2 (1 - Человек, любое другое число - Компьютер) : ";
	cin >> playerType;
	if (playerType == 1)
		this->player2 = new TicTacHumanPlayer();
	else
		this->player2 = new TicTacComputerPlayer();
	cin.ignore();
	cout << " Введите имя игрока, играещего X : ";
	getline(cin, playerName);
	player1->SetupPlayer(playerName, CellType_X);
	cout << " Введите имя игрока, играещего O : ";
	getline(cin, playerName);
	player2->SetupPlayer(playerName, CellType_O);
	player1->SetBoard(this->board);
	player2->SetBoard(this->board);
	currentPlayer = player1;
}

TicTacManager::~TicTacManager()
{
	delete this->player1;
	delete this->player2;
	delete this->board;
}

void TicTacManager::ShowBoard()
{	
	this->board->Show();
}

void TicTacManager::MakeMove()
{
	const string line = "\n---------------------------\n";
	ShowBoard();
	while (!currentPlayer->MakeMove())
	{
		cout << " Недопустимый ход попробуйте ещё раз\n\n";
		ShowBoard();
	}

	if (this->board->CheckEndCondition())
	{
		ShowBoard();
		if (this->board->isVictory())
			cout << line << " Игрок " << currentPlayer->GetName() << " победил!" << line;
		else
			cout << line << " Ничья!" << line;
		this->bGameFinished = true;
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

bool TicTacManager::isbGameFinished()
{
	return bGameFinished;
}