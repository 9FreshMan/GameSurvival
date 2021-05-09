#include "enemy.h"
#include <iostream>
#include <time.h>
using namespace std;

enemy::enemy()
{
	health = 10;
	y = 5;
	x = rand() % 180;
}

int enemy::GetHealth()
{
	return health;
}

void enemy::SetHealth(const int user)
{
	health = user;
}

int enemy::Getx()
{
	return x;
}

int enemy::Gety()
{
	return y;
}

void enemy::Setx(const int user)
{
	x = user;
}

void enemy::Sety(const int user)
{
	y = user;
}

