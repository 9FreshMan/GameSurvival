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
	if (a.GetMap()[a.GetPlayer().Gety() + 1][a.GetPlayer().Getx()] == char(219)) { a.GetPlayer().SetCountOfJumps(2); }
	if (a.GetPlayer().Gety() != a.GetSizey() - 2 && a.GetMap()[a.GetPlayer().Gety() + 1][a.GetPlayer().Getx()] != char(219)) {
		a.GetPlayer().Sety(a.GetPlayer().Gety() + 1);
	}
	for (int i = 0; i < 10;i++) {
		if (a.GetEnemy()[i].GetHealth() < 0) { a.GetEnemy()[i].Setx(2000); }
		if (a.GetEnemy()[i].Gety() != a.GetSizey() - 2 && a.GetMap()[a.GetEnemy()[i].Gety() + 1][a.GetEnemy()[i].Getx()] != char(219)) {
			a.GetEnemy()[i].Sety(a.GetEnemy()[i].Gety() + 1);
		}
		if (a.GetMap()[a.GetEnemy()[i].Gety() + 1][a.GetEnemy()[i].Getx()] == char(219)) {
			bool way = rand() % 2;
			if (way == 1) {
				if (a.GetMap()[a.GetEnemy()[i].Gety()][a.GetEnemy()[i].Getx() + 1] == char(219)) {
					a.GetEnemy()[i].Setx(a.GetEnemy()[i].Getx() + 1);
					a.GetEnemy()[i].Sety(a.GetEnemy()[i].Gety() - 1);
				}
				else {
					a.GetEnemy()[i].Setx(a.GetEnemy()[i].Getx() + 1);
					
				}
			}
			if (way == 0) {
			
				if (a.GetMap()[a.GetEnemy()[i].Gety()][a.GetEnemy()[i].Getx() - 1] == char(219)) {
					a.GetEnemy()[i].Setx(a.GetEnemy()[i].Getx() - 1);
					a.GetEnemy()[i].Sety(a.GetEnemy()[i].Gety() - 1);
				}
				else {
					a.GetEnemy()[i].Setx(a.GetEnemy()[i].Getx() - 1);

				}
			}
		}
	}bool damage = false;
	for (int i = 0; i < a.GetSizey(); i++) {
		for (int j = a.GetPlayer().Getx(); j < a.GetSizex(); j++) {
			if (a.GetPlayer().GetHealth() <= 0) { SetGameOver(1); }
			
			for (int k = 0; k < 10; k++) {
				if (a.GetPlayer().Getx() == a.GetEnemy()[k].Getx() && a.GetPlayer().Gety() == a.GetEnemy()[k].Gety()) {
					
					damage = true; break;
				}
				}
			
			if (j > a.GetCameraViewEnd()) { a.GetShoot()[i][j] = ' '; }
			if (a.GetShoot()[i][j] == char(253)) {
				for (int k = 0; k < 10; k++) {
					
					if (a.GetEnemy()[k].Getx() == j + 1) { a.GetEnemy()[k].SetHealth(a.GetEnemy()[k].GetHealth() - 10); }
				}
				if (a.GetMap()[i][j + 1] == char(219)) { a.GetShoot()[i][j] = ' ';}
				
				else {
					a.GetShoot()[i][j] = ' ';
					a.GetShoot()[i][j + 1] = char(253);
					j++;
				}
			}
		}
	
	}if (damage == true) { a.GetPlayer().SetHealth(a.GetPlayer().GetHealth() - 1); }
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
		case 'w': {a.GetShoot()[a.GetPlayer().Gety()-1][a.GetPlayer().Getx() + 3] = char(253); }
		}
	}
}

area game::GetArea()
{
	return a;
}

void game::WorldGeneration()
{
	a.Worldgeneration();
	//a.EnemyGeneration();
}

void game::SetGameOver(const bool user)
{
	gameOver = user;
}

bool game::GetGameOver()
{
	return gameOver;
}





