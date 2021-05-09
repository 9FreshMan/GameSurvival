#pragma once
#include "area.h"

class game
{
	area a;
	bool gameOver = false;
public:
	game();
	void out();
	void inp();
	area GetArea();
	void WorldGeneration();
	void SetGameOver(const bool user);
	bool GetGameOver();
};

