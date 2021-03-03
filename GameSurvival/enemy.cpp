#include "enemy.h"

enemy::enemy()
{
	x = 10;
	y = 90;
	health = 100;
}

int enemy::Getx()
{
	return x;
}

int enemy::Gety()
{
	return y;
}

int enemy::GetHealth()
{
	return health;
}

void enemy::Setx(const int userx)
{
	x = userx;
}

void enemy::Sety(const int usery)
{
	y = usery;
}

void enemy::SetHealth(const int user)
{
	health = user;
}
