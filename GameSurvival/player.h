#pragma once
class player
{
	int x;
	int y;
	int health;
public:
	player();
	int Getx();
	int Gety();
	int GetHealth();
	void Setx(const int userx);
	void Sety(const int usery);
	void SetHealth(const int user);
};

