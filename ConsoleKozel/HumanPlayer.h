#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(string n) : Player(n) {}
	bool makeMove(string hod, Cards& card);
};

