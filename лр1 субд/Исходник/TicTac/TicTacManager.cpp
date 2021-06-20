#include "TicTacManager.h"
#include "TicTacPlayer.h"
#include "TicTacHumanPlayer.h"
#include "TicTacComputerPlayer.h"

TicTacManager::TicTacManager()
{
	string playerName;
	int playerType;
	this->board = new TicTacBoard(8, 7);
	cout << " ������� ��� ������ #1 (1 - �������, ����� ������ ����� - ���������) : ";
	cin >> playerType;
	if (playerType == 1)
		this->player1 = new TicTacHumanPlayer();
	else
		this->player1 = new TicTacComputerPlayer();
	cout << " ������� ��� ������ #2 (1 - �������, ����� ������ ����� - ���������) : ";
	cin >> playerType;
	if (playerType == 1)
		this->player2 = new TicTacHumanPlayer();
	else
		this->player2 = new TicTacComputerPlayer();
	cin.ignore();
	cout << " ������� ��� ������, ��������� X : ";
	getline(cin, playerName);
	player1->SetupPlayer(playerName, CellType_X);
	cout << " ������� ��� ������, ��������� O : ";
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
		cout << " ������������ ��� ���������� ��� ���\n\n";
		ShowBoard();
	}

	if (this->board->CheckEndCondition())
	{
		ShowBoard();
		if (this->board->isVictory())
			cout << line << " ����� " << currentPlayer->GetName() << " �������!" << line;
		else
			cout << line << " �����!" << line;
		this->bGameFinished = true;
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

bool TicTacManager::isbGameFinished()
{
	return bGameFinished;
}