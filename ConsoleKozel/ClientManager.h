#pragma once
#include "Manager.h"
#include "Firebase.h"



class ClientManager : public Manager
{
public:
	Player* iamPlayer;
	string curPlayer;

	Firebase online;
public:
	ClientManager(UINT originalCP) : Manager(originalCP) {}
	~ClientManager();
	virtual void initGame();
	virtual void makeMove();
	void playerChose();
	void getCards();
};

