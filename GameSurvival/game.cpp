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
	/*for (int i = 0; i < a.GetSizey(); i++) {
		for (int j = 0; j < a.GetSizex(); j++) {
		if (a.GetMap()[i][j]!=char(219)&&a.GetPlayer().Gety()!=)
		}
	}*/
	if (a.GetPlayer().Gety() != a.GetSizey() - 2 && a.GetMap()[a.GetPlayer().Gety() + 1][a.GetPlayer().Getx()] != char(219)) {
		a.GetPlayer().Sety(a.GetPlayer().Gety() + 1);
	}
	
}

void game::inp()
{
	while (_kbhit()) {
		switch (_getch())
		{
		case 'a': {
			if (a.GetMap()[a.GetPlayer().Gety()][a.GetPlayer().Getx() - 1] == char(219)) { break; }
			a.SetCameraViewBegin(a.GetCameraViewBegin() - 1);
			a.SetCameraViewEnd(a.GetCameraViewEnd() - 1);
			a.GetPlayer().Setx(a.GetPlayer().Getx() - 1); break; }
		case 'd': {
			if (a.GetMap()[a.GetPlayer().Gety()][a.GetPlayer().Getx() + 1] == char(219)) { break; }
			a.SetCameraViewBegin(a.GetCameraViewBegin() + 1); 
			a.SetCameraViewEnd(a.GetCameraViewEnd() + 1);
			a.GetPlayer().Setx(a.GetPlayer().Getx() + 1); break; }
		case 32: {a.GetPlayer().Sety(a.GetPlayer().Gety() - 3); break; }
		}
	}
}

void game::WorldGeneration()
{
	a.Worldgeneration();
}
