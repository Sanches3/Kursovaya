#pragma once
#include "TicTacPlayer.h"

class TicTacComputerPlayer : public TicTacPlayer
{
public:
	TicTacComputerPlayer();
	virtual ~TicTacComputerPlayer();
	virtual bool MakeMove();
};