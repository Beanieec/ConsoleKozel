#pragma once
#include "Table.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Mode.h"

#include <iostream>
#include <string>

using namespace std;

class Manager
{

private:
	UINT originalCP;

	Table table;

	Player* currentPlayer = player1;
	Player* player1;
	Player* player2;
	Player* player3;
	Player* player4;

	Player* winPlayer;
	
	
	Cards lastCard = ukncard;
	Cards winCard = ukncard;
	
	string hod;
	Mast mMast;
	Mast gameMast;
	Mode mode = Start;
	

	int stepCounter = 0;
	int realScore = 0;
	int scoreT1 = 0;
	int scoreT2 = 0;
	int endScoreT1 = 0;
	int endScoreT2 = 0;

	//флаги
	bool isWasEggs = false;

public:
	Manager(UINT originalCP) { this->originalCP = originalCP; }
	void initGame();
	
private:
	void makeMove();
	bool checkAndCodition();
	void changePlayer();
	bool choseFirstPlayer();
	bool getWinDeal();

	bool choseMainMast();

	void printInfo();
	void printCard(Cards card);
	void printPack(Player* player);
	void printMast(Mast mast);
	
	
};

