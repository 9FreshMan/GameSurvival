#include "player.h"

player::player()
{
	x = 2;
	y = 2;
	health = 100;
	money = 0;
}

int player::Getx()
{
	return x;
}

int player::Gety()
{
	return y;
}

int player::GetHealth()
{
	return health;
}

int player::GetMoney()
{
	return money;
}

int player::GetCountOfJumps()
{
	return CountOfJumps;
}

void player::SetCountOfJumps(const int user)
{
	CountOfJumps = user;
}

void player::Setx(const int userx)
{
	x = userx;
}

void player::Sety(const int usery)
{
	y = usery;
}

void player::SetHealth(const int user)
{
	health = user;
}

void player::SetMoney(const int user)
{
	money = user;
}
