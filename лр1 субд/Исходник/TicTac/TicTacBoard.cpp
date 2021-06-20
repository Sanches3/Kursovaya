#include "TicTacBoard.h"
#include "pch.h"

TicTacBoard::TicTacBoard(unsigned int line, unsigned int column)
{
	this->boardline = line;
	this->boardcolumn = column;
	cells = new CellType*[line];
	for (unsigned int i = 0; i < line; i++)
		cells[i] = new CellType[column];
	for (unsigned int i = 0; i < line; i++)
		for (unsigned int j = 0; j < column; j++)
			cells[i][j] = CellType_Empty;
}

TicTacBoard::TicTacBoard(TicTacBoard* board)
{
	this->boardline = board->boardline;
	this->boardcolumn = board->boardcolumn;
	cells = new CellType * [boardline];
	for (unsigned int i = 0; i < boardline; i++)
		cells[i] = new CellType[boardcolumn];
	for (unsigned int i = 0; i < boardline; i++)
		for (unsigned int j = 0; j < boardcolumn; j++)
			cells[i][j] = board->cells[i][j];
}

TicTacBoard::~TicTacBoard()
{
	for (unsigned int i = 0; i < boardline; i++)
		delete[]cells[i];
	delete[]cells;
}

void TicTacBoard::Show()
{
	cout << "   ";
	for (unsigned int i = 0; i < boardcolumn; i++)
		cout << i << " ";
	cout << endl;
	for (unsigned int i = 0; i < boardline; i++)
	{
		cout << " " << i << " ";
		for (unsigned int j = 0; j < boardcolumn; j++)
		{
			switch (cells[i][j])
			{
			case CellType_X:
				cout << "X";
				break;
			case CellType_O:
				cout << "O";
				break;
			case CellType_Empty:
				cout << "-";
				break;
			}
			cout << " ";
		}
		cout << endl;
	}
}

void TicTacBoard::SetCell(unsigned int column, CellType ct)
{
	for (int i = boardline-1; i >= 0; i--)
		if (cells[i][column] == CellType_Empty)
		{
			cells[i][column] = ct;
			break;
		}
}

bool TicTacBoard::CheckLegal(unsigned int column)
{
	if ((column < 0) || (column >= boardcolumn))
		return false;
	return (cells[0][column] == CellType_Empty);
}

bool TicTacBoard::isColMade(unsigned int col)
{
	int NumX = 0, NumO = 0;
	for (unsigned int i = 0; i <= boardline; i++)
	{
		if (NumX == 4 || NumO == 4)
		{
			bVictory = true;
			return true;
		}

		if (i != boardline)
		{
			if (cells[i][col] == CellType_X)
				NumX++;
			else
				NumX = 0;

			if (cells[i][col] == CellType_O)
				NumO++;
			else
				NumO = 0;
		}
	}
	return false;
}

bool TicTacBoard::isRowMade(unsigned int row)
{
	int NumX = 0, NumO = 0;
	for (unsigned int i = 0; i <= boardcolumn; i++)
	{
		if (NumX == 4 || NumO == 4)
		{
			bVictory = true;
			return true;
		}

		if (i != boardcolumn)
		{
			if (cells[row][i] == CellType_X)
				NumX++;
			else
				NumX = 0;

			if (cells[row][i] == CellType_O)
				NumO++;
			else
				NumO = 0;
		}
	}
	return false;
}

bool TicTacBoard::isDiagMade()
{
	int NumX = 0, NumO = 0;

	for (int i = 0; i <= boardline - 4; i++)
	{
		for (int j = 0; j <= boardcolumn - 4; j++)
		{
			NumX = 0;
			NumO = 0;
			for (int k = 0; k < 4; k++)
			{
				NumX += (cells[i + k][j + k] == CellType_X);
				NumO += (cells[i + k][j + k] == CellType_O);
			}
			if ((NumX == 4) || (NumO == 4))
			{
				bVictory = true;
				return true;
			}
		}
	}

	for (int i = boardcolumn - 4 + 1; i < boardline; i++)
	{
		for (int j = 0; j <= boardcolumn - 4; j++)
		{
			NumX = 0;
			NumO = 0;
			for (int k = 0; k < 4; k++)
			{
				NumX += (cells[i - k][j + k] == CellType_X);
				NumO += (cells[i - k][j + k] == CellType_O);
			}
			if ((NumX == 4) || (NumO == 4))
			{
				bVictory = true;
				return true;
			}
		}
	}
	return false;
}

bool TicTacBoard::isBoardFull()
{
	int num = 0;
	for (unsigned int i = 0; i < boardline; i++)
		for (unsigned int j = 0; j < boardcolumn; j++)
		{
			if (cells[i][j] == CellType_O || cells[i][j] == CellType_X)
				num++;
		}
	if (num == boardline * boardcolumn)
		return true;

	return false;
}

bool TicTacBoard::CheckEndCondition()
{
	for (unsigned int i = 0; i < boardline; i++)
		if (isRowMade(i))
			return true;
	for (unsigned int i = 0; i < boardcolumn; i++)
		if (isColMade(i))
			return true;
	if (isDiagMade() || isBoardFull())
		return true;
	return false;
}

bool TicTacBoard::isVictory()
{
	return bVictory;
}