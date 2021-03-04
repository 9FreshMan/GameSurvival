#include "player.h"

player::player()
{
	x = 2;
	y = 2;
	health = 100;
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
