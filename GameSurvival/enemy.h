#pragma once
class enemy
{
	int x;
	int y;
	int health;
public:
	enemy();
	int GetHealth();
	void SetHealth(const int user);
	int Getx();
	void Sety(const int  user);
	int Gety();
	void Setx(const int  user);
};

