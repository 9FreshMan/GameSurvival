#include "area.h"
#include <iostream>
#include "time.h"
#include <conio.h>
#include <Windows.h>
using namespace std;

area::area()
{
	sizex = 200;
	sizey = 20;
	cameraviewx1 = 0;
	cameraviewx2 = 50;
	map = new char* [sizey];
	for (int i = 0; i < sizey; i++)
	{
		map[i] = new char[sizex];
	}
	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			if (i == sizey - 1) { map[i][j] = char(219); }
			else map[i][j] = ' ';
		}
	}
	map[sizey - 2][12] = char(219);
	map[sizey - 2][4] = char(219);
}

area::~area()
{
	for (int i = 0; i < sizey; i++) {
		delete[]map[i];
	}
	delete[]map;
}

void area::OutPut()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < sizey; i++) {
		for (int j = cameraviewx1; j < cameraviewx2; j++) {
			if (p.Getx() == j && p.Gety() == i) {
				SetConsoleTextAttribute(h, 1);
				cout << char(219) << char(219);
				SetConsoleTextAttribute(h, 15);
			}
			else if (e.Getx() == j && e.Gety() == i) {
				SetConsoleTextAttribute(h, 4);
				cout << char(219) << char(219);
				SetConsoleTextAttribute(h, 15);
			} //show enemy
			else if (map[i][j] == char(219)) {
				SetConsoleTextAttribute(h, 2);
				cout << char(219) << char(219);
				SetConsoleTextAttribute(h, 15);
			}
			else if (map[i][j] == ' ') { cout << "  "; }


		}
		cout << endl;
	}
	cout << "X: " << p.Getx() << "\tY: " << p.Gety() << endl;
	cout << "Health: " << p.GetHealth() << " " << endl;
	cout << "Money: " << p.GetMoney() << " " << endl;

	cout << "EX: " << e.Getx() << "\tEY: " << e.Gety() << endl;
}

player& area::GetPlayer()
{
	return p;
}

enemy& area::GetEnemy()
{
	return e;
}

void area::Worldgeneration()
{
	srand(time(NULL));

	for (int i = 0; i < sizey; i++) {
		for (int j = 0; j < sizex; j++) {
			if (map[i][j] == char(219) && map[i - 1][j] != char(219)) {
				int random = rand() % 2;
				if (random == 1) { map[i - 1][j] = char(219); }
			}
		}
	}
}

char** area::GetMap()
{
	return map;
}

void area::SetSizex(const int user)
{
	sizex = user;
}

void area::SetSizey(const int user)
{
	sizey = user;
}

int area::GetSizey()
{
	return sizey;
}

int area::GetSizex()
{
	return sizex;
}

int area::GetCameraViewBegin()
{
	return cameraviewx1;
}

int area::GetCameraViewEnd()
{
	return cameraviewx2;
}

void area::SetCameraViewBegin(const int user)
{
	cameraviewx1 = user;
}

void area::SetCameraViewEnd(const int user)
{
	cameraviewx2 = user;
}

void area::EnemyGeneration()
{
	int x = rand() % 9 + 10;
	int y = rand() % 9 + 10;
	e.Setx(x);
	e.Sety(y);
}
