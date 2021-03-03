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
218┌   ▄ 220
219█   █╒╦═ ∙∙∙∙∙∙∙∙219 213 203 205 249
220▄   ╙211
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
*/
int main() {
	game g;
	
	while (true)
	{
	g.out();
	
	setcur(0, 0);
		g.inp();
	}

	return 0;
}