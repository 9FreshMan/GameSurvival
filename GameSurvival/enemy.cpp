#include "enemy.h"

enemy::enemy()
{
	spawned = 0;
	health = 100;
}


int enemy::GetHealth()
{
	return health;
}

void enemy::SetHealth(const int user)
{
	health = user;
}

bool enemy::GetSpawned()
{
	return spawned;
}

void enemy::SetSpawned(const bool user)
{
	spawned = user;
}
