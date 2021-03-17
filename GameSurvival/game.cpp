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
	if (a.GetEnemy().Gety() != a.GetSizey() - 2 && a.GetMap()[a.GetEnemy().Gety() + 1][a.GetEnemy().Getx()] != char(219)) {
		a.GetEnemy().Sety(a.GetEnemy().Gety() + 1); //enemy physics
	}
	if (a.GetMap()[a.GetEnemy().Gety() + 1][a.GetEnemy().Getx()] == char(219))
	{
		EnemyWalk();
	}
	EnemyPunch();
	//EnemyWalk();
	//EnemyGen();
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
		case 32: {a.GetPlayer().Sety(a.GetPlayer().Gety() - 3); break; }
		}
	}
}

void game::WorldGeneration()
{
	a.Worldgeneration();
	//a.EnemyGeneration();
}

void game::EnemyWalk()
{
	for (int i = 0; i < 10; i++)
	{
		if (i % 7 == 0)
		{
			int random = rand() % 10;
			switch (random)
			{
			case 1:case 3:case 5: case 7: case 9:
			{
				if (a.GetMap()[a.GetEnemy().Gety()][a.GetEnemy().Getx() - 1] == char(219))
					break;
				a.GetEnemy().Setx(a.GetEnemy().Getx() - 1);
			} break;
			case 2: case 4: case 6: case 8: case 10:
			{
				if (a.GetMap()[a.GetEnemy().Gety()][a.GetEnemy().Getx() + 1] == char(219))
					break;
				a.GetEnemy().Setx(a.GetEnemy().Getx() + 1);

			} break;
			}
			if (a.GetMap()[a.GetEnemy().Gety()][a.GetEnemy().Getx() - 1] == char(219) && a.GetMap()[a.GetEnemy().Gety()][a.GetEnemy().Getx() + 1] == char(219) || a.GetMap()[a.GetEnemy().Gety()][a.GetEnemy().Getx() - 2] == char(219) && a.GetMap()[a.GetEnemy().Gety()][a.GetEnemy().Getx() + 2] == char(219))
			{
				a.GetEnemy().Sety(a.GetEnemy().Gety() - 3);
				/*if (random % 2 == 0)
				{
					a.GetEnemy().Setx(a.GetEnemy().Getx() + 2);
				}
				else
				{
					a.GetEnemy().Setx(a.GetEnemy().Getx() - 2);
				}*/
			}
		}
	}
}

void game::EnemyPunch()
{
	if (a.GetPlayer().Getx() == a.GetEnemy().Getx() && a.GetPlayer().Gety() == a.GetEnemy().Gety())
	{
		a.GetPlayer().SetHealth(a.GetPlayer().GetHealth() - 1);
	}
}
