#pragma once
#include "Cards.h"
#include "Player.h"

#include <iostream>
#include <random>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class Table
{
private:
public:
	Table();
	vector<Cards> pack;

public:
	void packShuffle();
	void givingCards(Player* player);

};

