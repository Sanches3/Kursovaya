#pragma once
#include "TicTacPlayer.h"

class TicTacHumanPlayer : public TicTacPlayer
{
public:
	TicTacHumanPlayer();
	virtual ~TicTacHumanPlayer();
	virtual bool MakeMove();
};

