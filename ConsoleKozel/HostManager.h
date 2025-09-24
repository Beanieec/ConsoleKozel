#pragma once
#include "Manager.h"
class HostManager : public Manager
{
public:
	Player* iamPlayer;
public:
	HostManager(UINT originalCP) : Manager(originalCP) {}
	virtual void initGame();
	virtual void makeMove();
};

