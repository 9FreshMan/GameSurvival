#pragma once
#include "character.h"
class enemy : public character
{
	private:

	public:
		enemy();
		void SetX(const int x);
		void SetY(const int y);
		int GetX();
		int GetY();
		int GetHealth();
		void SetHealth(const int h);
};

