#pragma once
#include "Cards.h"

#include <vector>
#include <string>

using namespace std;

class Player
{
public:
	CardsType lastHod;
	string name;
	vector<CardsType> hand;
public:
	Player(string n) : name(n){}
	virtual bool makeMove(CardsType hod) = 0;
	void choseDeal();
};

