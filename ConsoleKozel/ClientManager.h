#pragma once
#include "Manager.h"
#include "Firebase.h"


class ClientManager : public Manager
{
public:
	Player* iamPlayer;

	Firebase online;
public:
	ClientManager(UINT originalCP) : Manager(originalCP) {}
	virtual void initGame();
	virtual void makeMove();
};

