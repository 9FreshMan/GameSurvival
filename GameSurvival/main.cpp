#include <iostream>
#include "game.h"

#include <conio.h>
#include <Windows.h>
using namespace std;
void setcur(int x, int y)//установка курсора на позицию  x y 
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
/*
		Black         = 0,
		Blue          = 1,
		Green         = 2,
		Cyan          = 3,
		Red           = 4,
		Magenta       = 5,
		Brown         = 6,
		LightGray     = 7,
	   &nbsp;DarkGray      = 8,
		LightBlue     = 9,
		LightGreen    = 10,
		LightCyan     = 11,
		LightRed      = 12,
		LightMagenta  = 13,
		Yellow        = 14,
		White         = 15

*/
/*

176░
177▒
178▓
179│
180┤
181╡
182╢
183╖
184╕
185╣
186║++++++++++++
187╗+++++++++++++++++++++
188╝+++++++++++++++++++
189╜
190╛
191┐
192└
193┴
194┬
195├
196─
197┼
198╞
199╟
200╚++++++++++++++++++++++++
201╔+++++++++++++++++++++
202╩++++++++++++++++++
203╦++++++++++++++
204╠
205═+++++++++++++++++++
206╬
207╧
208╨
209╤
210╥
211╙
212╘
213╒    ╤
214╓    ╓╖
215╫
216╪
217┘
218┌   ╓╖ 220
219█   ██╒╦═ ∙∙∙∙∙∙∙∙219 213 203 205 249
220▄   ╙╙211
221▌
222▐
223▀
248°
249∙
250·
251√
252№
253¤
254■
  ╓╖ 
 ╚██╝
  ╙╙
*/
int  menu(COORD c, INPUT_RECORD all_events) {
	int choose = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 9);
	setcur(10, 0);
	int ls = 10;
	for (int i = 0; i < 3; i++) {
		setcur(ls, i);
		for (int j = 0; j < 9; j++) {
			if (i == 0 || j == 0 || i == 2 || j == 8) {
				if (c.Y >= 0 && c.Y <= 2 && c.X >= 10 && c.X <= 18) {
					SetConsoleTextAttribute(h, 2);
					cout << char(219);
				}
				else { cout << char(219); }
			}
			else if (i == 1 && j == 1) {
				if (c.Y >= 0 && c.Y <= 2 && c.X >= 10 && c.X <= 18) {
					SetConsoleTextAttribute(h, 9);
					cout << "P L A Y"; SetConsoleTextAttribute(h, 9);
				}
				else { SetConsoleTextAttribute(h, 2); cout << "P L A Y"; SetConsoleTextAttribute(h, 9); }
			}
			else if (i != 1 && j != 1) cout << " ";
		}
		cout << endl;
	}
	setcur(10, 6);
	ls = 8;
	SetConsoleTextAttribute(h, 9);
	for (int i = 0; i < 3; i++) {
		setcur(ls, i + 5);
		for (int j = 0; j < 13; j++) {
			if (i == 0 || j == 0 || i == 2 || j == 12) {
				if (c.Y >= 5 && c.Y <= 7 && c.X >= 8 && c.X <= 20) {
					SetConsoleTextAttribute(h, 2);
					cout << char(219);
				}
				else { cout << char(219); }
			}
			else if (i == 1 && j == 1) {
				if (c.Y >= 5 && c.Y <= 7 && c.X >= 8 && c.X <= 20) {
					SetConsoleTextAttribute(h, 9);
					cout << "HOW TO PLAY"; SetConsoleTextAttribute(h, 9);
				}
				else { SetConsoleTextAttribute(h, 2); cout << "HOW TO PLAY"; SetConsoleTextAttribute(h, 9); }
			}
			else if (i != 1 && j != 1) cout << " ";
		}
		cout << endl;
	}
	SetConsoleTextAttribute(h, 9);
	setcur(10, 12);
	ls = 10;
	for (int i = 0; i < 3; i++) {
		setcur(ls, i + 10);
		for (int j = 0; j < 9; j++) {
			if (i == 0 || j == 0 || i == 2 || j == 8) {
				if (c.Y >= 10 && c.Y <= 12 && c.X >= 10 && c.X <= 18) {
					SetConsoleTextAttribute(h, 2);
					cout << char(219);
				}
				else { cout << char(219); }
			}
			else if (i == 1 && j == 1) {
				if (c.Y >= 10 && c.Y <= 12 && c.X >= 10 && c.X <= 18) {
					SetConsoleTextAttribute(h, 9);
					cout << "E X I T"; SetConsoleTextAttribute(h, 9);
				}
				else { SetConsoleTextAttribute(h, 2); cout << "E X I T"; SetConsoleTextAttribute(h, 9); }
			}
			else if (i != 1 && j != 1) cout << " ";

		}
		cout << endl;
	}
	//Play 
	if (all_events.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y >= 0 && c.Y <= 3 && c.X >= 10 && c.X <= 18) {
		choose = 1;

	}
	//How to play
	if (all_events.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y >= 5 && c.Y <= 7 && c.X >= 8 && c.X <= 20) {
		choose = 2;

	}
	//Exit
	if (all_events.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && c.Y >= 10 && c.Y <= 12 && c.X >= 10 && c.X <= 18) {
		choose = 3;

	}
	return choose;
}
void fontsize(int a, int b) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
	lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
	GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
	lpConsoleCurrentFontEx->dwFontSize.X = a;
	lpConsoleCurrentFontEx->dwFontSize.Y = b;
	SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
}
void gameo() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 30; i++) {
		if (i % 2 == 0) {
			SetConsoleTextAttribute(h, 4);
		}
		else { SetConsoleTextAttribute(h, 2); }
		setcur(i, 4);
		cout << "_$$$$___$$$$__$$___$_$$$$$" << endl; setcur(i, 5);
		cout << "$$_____$$__$$_$$$_$$_$$" << endl; setcur(i, 6);
		cout << "$$_$$$_$$$$$$_$$_$_$_$$$$" << endl; setcur(i, 7);
		cout << "$$__$$_$$__$$_$$___$_$$" << endl; setcur(i, 8);
		cout << "_$$$$__$$__$$_$$___$_$$$$$" << endl; setcur(i, 9);
		cout << endl;
		setcur(i, 10);
		cout << "_$$$$__$$__$$_$$$$$__$$$$$" << endl; setcur(i, 11);
		cout << "$$__$$_$$__$$_$$_____$$__$$" << endl; setcur(i, 12);
		cout << "$$__$$_$$__$$_$$$$___$$$$$" << endl; setcur(i, 13);
		cout << "$$__$$__$$$$__$$_____$$__$$" << endl; setcur(i, 14);
		cout << "_$$$$____$$___$$$$$__$$__$$" << endl; setcur(i, 15);
		system("cls");
	}
}
int main() {
	
	COORD c;
	DWORD a;
	INPUT_RECORD all_events;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	fontsize(20, 20);
	
	while (true)
	{
		HANDLE hin = GetStdHandle(STD_INPUT_HANDLE); // дескриптор окна для работы с мышкой
		SetConsoleMode(hin, ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS); // установка режима использования мышки
	ReadConsoleInput(hin, &all_events, 1, &a);
	c.X = all_events.Event.MouseEvent.dwMousePosition.X; // запомнить координаты мышки
	c.Y = all_events.Event.MouseEvent.dwMousePosition.Y;
	int menuresult = menu(c, all_events);
	switch (menuresult)
	{
	case 1: {  
		game g;
		for (int i = 0; i < 1; i++) {
			g.WorldGeneration();
		}
		while (true)
		{
			setcur(0, 0);
		if (g.GetGameOver() == true) { system("cls"); gameo(); break; }
		g.out();
		g.inp();
		
		Sleep(10);
		}break; }
	case 2: {break; }
	case 3: {gameo();
		  break;
	}
	default:
		break;
	}
	
	}
	
	return 0;
}