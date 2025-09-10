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

	CardsType lastCard = ukncard;
	
public:
	Manager(UINT originalCP) { this->originalCP = originalCP; }
	void initGame();
	void makeMove();

	string cardToString(CardsType card);
	CardsType stringToCard(string card);
	void printPack(Player* player);
	void printCard(CardsType card);


};

