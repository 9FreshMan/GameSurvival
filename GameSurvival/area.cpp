#include "area.h"
#include <iostream>
using namespace std;

area::area()
{
	sizex = 200;
	sizey = 20;
	cameraviewx1 = 0;
	cameraviewx2 = 10;
	map = new char*[sizey];
	for (int i=0; i<sizey; i++)
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
	for (int i = 0; i < sizey; i++) {
		for (int j = cameraviewx1; j < cameraviewx2; j++) {
			if (p.Getx() == j && p.Gety() == i) { cout << char(219) << char(219); }
			else if (map[i][j] == char(219)) { cout << char(219) << char(219); }
			else if (map[i][j] == ' ') { cout << "  "; }
			
			
		}
		cout << endl;
	}
	cout << p.Getx() << p.Gety();
}

player& area::GetPlayer()
{
	return p;
}

void area::Worldgeneration()
{

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
