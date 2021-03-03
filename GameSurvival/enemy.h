#pragma once
class enemy
{
	int x;
	int y;
	int health;
public:
	enemy();
	int Getx();
	int Gety();
	int GetHealth();
	void Setx(const int userx);
	void Sety(const int usery);
	void SetHealth(const int user);
};

