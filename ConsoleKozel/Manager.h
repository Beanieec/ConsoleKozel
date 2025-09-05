#pragma once
#include "Table.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#include <iostream>

using namespace std;

class Manager
{
private:
	Table table;
	Player* currentPlayer;
	Player* player1;
	Player* player2;
	Player* player3;
	Player* player4;
	
public:
	void initGame();


};

