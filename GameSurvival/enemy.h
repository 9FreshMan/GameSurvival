#pragma once
class enemy
{
	bool spawned;
	int health;
public:
	enemy();
	int GetHealth();
	void SetHealth(const int user);
	bool GetSpawned();
	void SetSpawned(const bool user);
};

