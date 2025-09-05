#pragma once
#include "Cards.h"

#include <vector>
#include <string>

using namespace std;

class Player
{
public:
	string name;
	vector<CardsType> hand;
public:
	Player(string n) : name(n){}
	virtual void makeMove() = 0;
	void choseDeal();
};

