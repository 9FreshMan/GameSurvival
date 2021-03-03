#include "game.h"
#include "area.h"
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
		case 'a': {a.GetPlayer().Setx(5); break;  }
		/*case 'd': {a.GetPlayer().SetX(a.GetPlayer().GetX() - 1); break; }
		case 'w': {a.GetPlayer().SetY(a.GetPlayer().GetY() - 1); break; }
		case 's': {a.GetPlayer().SetY(a.GetPlayer().GetY() + 1); break; }*/
		}
	}
}
