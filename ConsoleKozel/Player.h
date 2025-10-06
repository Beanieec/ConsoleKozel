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
	virtual bool makeMove(string hod, Cards& card, Mast mast) = 0;
	virtual bool HonestlyMakeMove(string hod, Cards firstCard, Cards& card, Mast mast) = 0;
	void choseDeal();
};

