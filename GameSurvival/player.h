#pragma once
#include "character.h"
class player :
	public character
{

public:
	player() :character()
	{
		health = 100;
		x = 12;
		y = 14;
	}
	void SetHealth(const int user);
	int GetHealth();
	int GetX();
	int GetY();
	void SetX(const int userx);
	void SetY(const int usery);
};

