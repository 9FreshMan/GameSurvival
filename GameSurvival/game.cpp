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
	if (a.GetMap()[a.GetPlayer().Gety() + 1][a.GetPlayer().Getx()] == char(219)) { a.GetPlayer().SetCountOfJumps(2); }
	if (a.GetPlayer().Gety() != a.GetSizey() - 2 && a.GetMap()[a.GetPlayer().Gety() + 1][a.GetPlayer().Getx()] != char(219)) {
		a.GetPlayer().Sety(a.GetPlayer().Gety() + 1);
	}
	
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 200; j++) {
			if (a.GetShoot()[i][j] == char(253)) {
				if (a.GetMap()[i][j + 1] == char(219)) { a.GetShoot()[i][j] = ' ';}
				else {
					a.GetShoot()[i][j] = ' ';
					a.GetShoot()[i][j + 1] = char(253);
					j++;
				}
			}
		}
	
	}
}

void game::inp()
{
	while (_kbhit()) {
		switch (_getch())
		{
		case 'a': {
			if (a.GetMap()[a.GetPlayer().Gety()][a.GetPlayer().Getx() - 1] == char(219) && a.GetMap()[a.GetPlayer().Gety() - 1][a.GetPlayer().Getx() - 1] == char(219)) {
				break;
			}
			if (a.GetMap()[a.GetPlayer().Gety()][a.GetPlayer().Getx() - 1] == char(219)&& a.GetMap()[a.GetPlayer().Gety()-1][a.GetPlayer().Getx() - 1] == ' ') {
				a.SetCameraViewBegin(a.GetCameraViewBegin() - 1);
				a.SetCameraViewEnd(a.GetCameraViewEnd() - 1);
				a.GetPlayer().Setx(a.GetPlayer().Getx() - 1); 
				a.GetPlayer().Sety(a.GetPlayer().Gety() - 1); 
				break;
			
			}
			a.SetCameraViewBegin(a.GetCameraViewBegin() - 1);
			a.SetCameraViewEnd(a.GetCameraViewEnd() - 1);
			a.GetPlayer().Setx(a.GetPlayer().Getx() - 1); break; }
		case 'd': {
			if (a.GetMap()[a.GetPlayer().Gety()][a.GetPlayer().Getx() + 1] == char(219) && a.GetMap()[a.GetPlayer().Gety() - 1][a.GetPlayer().Getx() + 1] == char(219)) {
			break;
		}
			if (a.GetMap()[a.GetPlayer().Gety()][a.GetPlayer().Getx() + 1] == char(219) && a.GetMap()[a.GetPlayer().Gety() - 1][a.GetPlayer().Getx() + 1] == ' ') {
				a.SetCameraViewBegin(a.GetCameraViewBegin() + 1);
				a.SetCameraViewEnd(a.GetCameraViewEnd() + 1);
				a.GetPlayer().Setx(a.GetPlayer().Getx() + 1); 
				a.GetPlayer().Sety(a.GetPlayer().Gety() - 1); 
				break;
			
			}
			a.SetCameraViewBegin(a.GetCameraViewBegin() + 1);
			a.SetCameraViewEnd(a.GetCameraViewEnd() + 1);
			a.GetPlayer().Setx(a.GetPlayer().Getx() + 1); break; }
		case 32: {if (a.GetPlayer().GetCountOfJumps() == 0) { break; }
			   else {
			a.GetPlayer().SetCountOfJumps(a.GetPlayer().GetCountOfJumps() - 1);
			a.GetPlayer().Sety(a.GetPlayer().Gety() - 3); break;
		} }
		case 'w': {a.GetShoot()[a.GetPlayer().Gety()][a.GetPlayer().Getx() + 1] = char(253); }
		}
	}
}

void game::WorldGeneration()
{
	a.Worldgeneration();
	//a.EnemyGeneration();
}



