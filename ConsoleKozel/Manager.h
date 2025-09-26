#define WIN32_LEAN_AND_MEAN
#define NOBYTE
#include <windows.h>
#pragma once
#include "Table.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Mode.h"


#include <iostream>
#include <string>
#include <sstream>



using namespace std;


class Manager
{

public:
	UINT originalCP;

	

	Table table;

	Player* currentPlayer = player1;
	Player* player1;
	Player* player2;
	Player* player3;
	Player* player4;

	Player* dealChooser;
	Player* winPlayer;

	Player* shahaPlayer;
	Player* qPlayer;
	
	
	Cards lastCard = ukncard;
	Cards winCard = ukncard;
	
	string hod;
	string mast;
	Mast mMast;
	Mast gameMast;
	Mode mode = Start;
	Mode deal = First;
	

	int stepCounter = 0;
	int realScore = 0;
	int scoreT1 = 0;
	int scoreT2 = 0;
	int endScoreT1 = 0;
	int endScoreT2 = 0;
	int countRounder = 0;

	//флаги
	int Eggs = 0;
	bool shaha = false;
	bool Q = false;

public:
	Manager(UINT originalCP) : originalCP(originalCP){}
	virtual void initGame() = 0;
	
	virtual void makeMove() = 0;
	bool checkAndCodition();
	bool findShaha();
	void changePlayer();
	void changeDealChooser();
	bool choseFirstPlayer();
	bool getWinDeal();

	void choseDeal(int deal);
	bool countRound(int count);

	bool choseMainMast();

	void printInfo();
	void printCard(Cards card);
	void printPack(Player* player);
	void printMast(Mast mast);
	void defValue();
	
	
};

