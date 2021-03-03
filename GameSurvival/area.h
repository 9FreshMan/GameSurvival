#pragma once
#include "player.h"
#include "enemy.h"
class area
{
	player p;
	enemy e;
	char** map;
	int sizex;
	int sizey;
public:
	area();
	~area();
	void OutPut();
	player GetPlayer();
};

