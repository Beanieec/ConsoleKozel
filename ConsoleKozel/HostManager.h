#pragma once
#include "Manager.h"
#include "Firebase.h"


class HostManager : public Manager
{
public:
	Player* iamPlayer;

	Firebase online;

	string lasthod = "";
public:
	HostManager(UINT originalCP) : Manager(originalCP) {}
	virtual void initGame();
	virtual void makeMove();
	void playerChose();
	void getCurrentPlayer();
};

