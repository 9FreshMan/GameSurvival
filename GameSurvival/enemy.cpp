#include "enemy.h"


enemy::enemy():character()
{
	health = 100;
	x = 0;
	y = 0;
}

int enemy::GetHealth()
{
	return health;
}

int enemy::GetX()
{
	return x;
}

int enemy::GetY()
{
	return y;
}

void enemy::SetHealth(const int h)
{
	health = h;
}

void enemy::SetX(const int x)
{
	this -> x = x;
}

void enemy::SetY(const int y)
{
	this -> y = y;
}