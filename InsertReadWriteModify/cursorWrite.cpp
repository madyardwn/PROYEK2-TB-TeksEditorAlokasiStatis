#include "cursorWrite.h"

void LastCursor(short row, short col)
{
	POINT p;
	if (GetCursorPos(&p))
	{
		row = p.x;
		col = p.y;
	}
}

void gotoxy(short x, short y)
{
	COORD pos ={x,y};
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}