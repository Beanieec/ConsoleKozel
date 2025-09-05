#pragma once
#include "Cards.h"
#include "Player.h"

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

class Table
{

public:
	Table();
	vector<CardsType> pack;
	/*vector<CardsType> playerHand;*/
public:
	void packShuffle();
	string cardToString(CardsType card);
	void printPack(Player* player);
	void givingCards(Player* player);

};

