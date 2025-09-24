#pragma once
#include "Manager.h"
class ClientManager : public Manager
{
public:
	ClientManager(UINT originalCP) : Manager(originalCP) {}
	virtual void initGame();
	virtual void makeMove();
};

