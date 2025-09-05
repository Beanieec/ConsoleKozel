#pragma once
#include "Player.h"

class HumanPlayer : public Player
{
private:
public:
	HumanPlayer(string n) : Player(n) {}
	void makeMove();
};

