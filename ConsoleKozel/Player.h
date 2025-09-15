#pragma once
#include "Cards.h"

#include <vector>
#include <string>

using namespace std;

class Player
{
public:
	Cards lastHod = ukncard;
	string name;
	vector<Cards> hand;
public:
	Player(string n) : name(n){}
	virtual bool makeMove(string hod, Cards& card) = 0;
	void choseDeal();
};

