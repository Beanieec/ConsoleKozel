#pragma once
#include "Manager.h"
class SingleManager : public Manager
{
public:
	SingleManager(UINT originalCP) : Manager(originalCP) {}
	virtual void initGame();
	virtual void makeMove();
};

