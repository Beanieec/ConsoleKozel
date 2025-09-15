#pragma once
#include "Table.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

#include <iostream>
#include <string>

using namespace std;

class Manager
{

private:
	UINT originalCP;

	Table table;

	Player* currentPlayer;
	Player* player1;
	Player* player2;
	Player* player3;
	Player* player4;

	

	Cards lastCard = ukncard;
	Mast mMast;
	
public:
	Manager(UINT originalCP) { this->originalCP = originalCP; }
	void initGame();
	void makeMove();

	void printCard(Cards card);
	void printPack(Player* player);
	void printMast(Mast mast);
	
	bool mainMast();
	//CardsType stringToCard(string card);
	//string cardToString(CardsType card);
	//int cardToPoint(CardsType card);

};

