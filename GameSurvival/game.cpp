#include "game.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;
game::game()
{
}
void game::out()
{

	a.OutPut();

}

void game::inp()
{
	while (_kbhit()) {
		switch (_getch())
		{
		case 'a': {a.GetPlayer().Setx(a.GetPlayer().Getx() - 1); break; }
		case 'd': {a.GetPlayer().Setx(a.GetPlayer().Getx() + 1); break; }
		case 'w': {a.GetPlayer().Sety(a.GetPlayer().Gety() - 1); break; }
		case 's': {a.GetPlayer().Sety(a.GetPlayer().Gety() + 1); break; }
		}
	}
}
