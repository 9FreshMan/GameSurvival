#include "area.h"
#include <iostream>
using namespace std;

area::area()
{
	sizex = 20;
	sizey = 20;
	map = new char*[sizex];
	for (int i=0; i<sizey; i++)
	{
		map[i] = new char[sizey];
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
	p.Setx(11);
	for (int i = 0; i < sizey; i++) {
	
		for (int j = 0; j < sizex; j++) {
			if (i == sizey - 1) {
				cout << char(219) << char(219);
			}
			
			else if (j == 0 || j == sizex - 1) {
				cout << char(219)<<char(219);
			}
			else if (p.Getx() == j && p.Gety() == i) { cout << char(219) << char(219); }
			else cout << "  ";
		}
		cout << endl;
	}
	cout << p.Getx() << p.Gety();
}

player area::GetPlayer()
{
	return p;
}
