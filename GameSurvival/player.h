#pragma once
class player
{
	int CountOfJumps = 2;
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
	int GetCountOfJumps();
	void SetCountOfJumps(const int user);
	void Setx(const int userx);
	void Sety(const int usery);
	void SetHealth(const int user);
	void SetMoney(const int user);
};

