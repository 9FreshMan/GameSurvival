#include "player.h"

void player::SetHealth(const int user)
{
	health = user;
}

int player::GetHealth()
{
	return health;
}

int player::GetX()
{
	return x;
}

int player::GetY()
{
	return y;
}


void player::SetX(const int userx)
{

	x = userx;
}	 



void player::SetY(const int usery)
{
	y= usery;
}