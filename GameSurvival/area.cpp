#include "area.h"
#include <iostream>
#include "time.h"
#include <conio.h>
#include <Windows.h>
using namespace std;
void setcur1(int x, int y)//установка курсора на позицию  x y 
{
	COORD coord;
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
area::area()
{
	shoot = new char* [20];
	for (int i = 0; i < 20; i++) {
		shoot[i] = new char[2000];
	}
	for (int i = 0; i < 20; i++) {
	
		for (int j = 0; j < 200; j++) {
		
			shoot[i][j] =  ' ';
		}
	}
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 200; j++) {

			shoot[i][j] = ' ';
		}
	}
	srand(time(NULL));
	e = new enemy[10];
	sizex = 2000;
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
		for (int j = cameraviewx1; j < cameraviewx2+8; j++) {
			bool flag = false;
			for (int k = 0; k < 10; k++) {
				if (e[k].Getx() == j && e[k].Gety() == i)
				{
				flag = true;
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(219)<<char(219);
				SetConsoleTextAttribute(h, 15);

				}

			}
			if (p.Getx() == j && p.Gety() - 2 == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(214);
				SetConsoleTextAttribute(h, 15);
			}
			else if (p.Getx() + 1 == j && p.Gety() - 2 == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(183);
				SetConsoleTextAttribute(h, 15);
			}
			
			else if (p.Getx() == j && p.Gety()-1 == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(219);
				SetConsoleTextAttribute(h, 15);
			}
			else if (p.Getx()+1 == j && p.Gety() - 1 == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(219);
				SetConsoleTextAttribute(h, 15);
			}
			else if (p.Getx()+2 == j && p.Gety() - 1 == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(213);
				SetConsoleTextAttribute(h, 15);
			}
			else if (p.Getx()+3 == j && p.Gety() - 1 == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(203) ;
				SetConsoleTextAttribute(h, 15);
			}
			else if (p.Getx()+4 == j && p.Gety() - 1 == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout <<char(205);
				SetConsoleTextAttribute(h, 15);
			}
			
			else if (p.Getx() == j && p.Gety() == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(186);
				SetConsoleTextAttribute(h, 15);
			}
			else if (p.Getx()+1 == j && p.Gety() == i) {
				SetConsoleTextAttribute(h, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0);
				cout << char(186);
				SetConsoleTextAttribute(h, 15);
			}
				
			
			
			else if (shoot[i][j] == char(253)) {
				SetConsoleTextAttribute(h, BACKGROUND_RED| BACKGROUND_BLUE | BACKGROUND_GREEN | 0); cout << char(253); SetConsoleTextAttribute(h, 15);
			}
			else if (map[i][j] == char(219)) {
				SetConsoleTextAttribute(h, 2);
				cout << char(219) << char(219);
				SetConsoleTextAttribute(h, 15);
			}
			else if (map[i][j] == ' '&&!flag) {
					SetConsoleTextAttribute(h, 7);
					cout << char(219) << char(219);
					SetConsoleTextAttribute(h, 15);
			}
			
			

		}
		cout << endl;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = cameraviewx1; j < cameraviewx2+8; j++) {
			SetConsoleTextAttribute(h, 6);
			cout << char(219) << char(219);
			SetConsoleTextAttribute(h, 15);
		}
		cout << endl;
	}
	cout << "Health: " << p.GetHealth() << " " << endl;
	
	
}

player& area::GetPlayer()
{
	return p;
}

enemy* area::GetEnemy()
{
	return e;
}

char** area::GetShoot()
{
	return shoot;
}

void area::SetShoot(int i, int j, char user)
{
	shoot[i][j] = user;
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


