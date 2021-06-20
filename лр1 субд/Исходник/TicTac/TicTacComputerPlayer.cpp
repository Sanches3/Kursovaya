#include "TicTacComputerPlayer.h"
#include "TicTacBoardMonteCarloEvaluator.h"

TicTacComputerPlayer::TicTacComputerPlayer()
{

}

TicTacComputerPlayer::~TicTacComputerPlayer()
{

}

bool TicTacComputerPlayer::MakeMove()
{
	cout << "\n Ход компьютера:" << endl;
	vector <TicTacBoardMonteCarloEvaluator*> evaluators;
	for (unsigned int i = 0; i < 7; i++)
		if (this->board->CheckLegal(i))
			evaluators.push_back(new TicTacBoardMonteCarloEvaluator(this->board, 1000, (this->cellType == CellType_X) ? CellType_O : CellType_X, i));
	
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
		(*evaluator)->Evaluate();

	int biggestVictories = -1;

	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
		if (this->cellType == CellType_X)
		{
			if ((*evaluator)->GetVictories() > biggestVictories)
				biggestVictories = (*evaluator)->GetVictories();
		}
		else
		{
			if ((*evaluator)->GetLosses() > biggestVictories)
				biggestVictories = (*evaluator)->GetLosses();
		}

	vector <TicTacBoardMonteCarloEvaluator*> biggestWinEvaluators;
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
	{
		int numVictories;
		if (this->cellType == CellType_X)
			numVictories = (*evaluator)->GetVictories();
		else
			numVictories = (*evaluator)->GetLosses();
		if (numVictories == biggestVictories)
			biggestWinEvaluators.push_back((*evaluator));
	}

	this->board->SetCell(biggestWinEvaluators[0]->GetColPos(), this->cellType);
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
		delete(*evaluator);
	evaluators.clear();
	biggestWinEvaluators.clear();
	
	return true;
}