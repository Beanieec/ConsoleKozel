#pragma once
#include "Cards.h"
#include "Player.h"

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>



class Table
{
private:
public:
	Table();
	std::vector<Cards> pack;

public:
	void packShuffle();
	void clearHand(Player* player);
	void givingCards(Player* player);
	void givingBigTits(Player* player);

};

