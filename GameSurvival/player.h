#pragma once
class player
{
	int x;
	int y;
	int health;
	int money;
public:
	player();
	int Getx();
	int Gety();
	int GetHealth();
	int GetMoney();

	void Setx(const int userx);
	void Sety(const int usery);
	void SetHealth(const int user);
	void SetMoney(const int user);
};

