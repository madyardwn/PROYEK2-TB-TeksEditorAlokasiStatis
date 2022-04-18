#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "design.h"
#include "input.h"

void gotoxy(int baris,int kolom)
{
	COORD coord;
	
    coord.X = kolom;
    coord.Y = baris;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void manualBook(){
	system("cls");
	printf("\t=========================================================================================  \n\n");
	printf("\t  ||||       |||   |||      |||  |||     |||  |||||||||                |||   ||||||||||    \n"); 
	printf("\t  ||||||     |||   |||      |||   |||   |||      |||                   |||   |||           \n");
	printf("\t  ||| |||    |||   |||      |||    ||| |||       |||                   |||   |||           \n");
	printf("\t  |||  |||   |||   |||      |||     |||||        |||                   |||   |||           \n");
	printf("\t  |||   |||  |||   |||      |||      |||         |||                   |||   ||||||||||    \n");
	printf("\t  |||    ||| |||   |||      |||     |||||        |||           |||     |||          |||    \n");
	printf("\t  |||     ||||||   |||      |||    ||| |||       |||           |||     |||          |||    \n");
	printf("\t  |||      |||||   |||      |||   |||   |||      |||           |||     |||          |||    \n");
	printf("\t  |||       ||||   ||||||||||||  |||     |||     |||     |||   |||||||||||   ||||||||||    \n\n");
	printf("\t========================================================================================== \n");
	printf("\t=====                                   TEXT EDITOR                                    === \n");
	printf("\t========================================================================================== \n");
	printf("\t========================================================================================== \n");
	printf("\t=====                  Aplikasi ini dibangun menggunakan bahasa C                      === \n");
	printf("\t=====                     yang memiliki fitur seperti notepad                          === \n");
	printf("\t========================================================================================== \n");
	printf("\t=====                                 Dibuat oleh :                                    === \n");
	printf("\t=====                                 - Achmadya                                       === \n");
	printf("\t=====                                 - Aurell                                         === \n");
	printf("\t=====                                 - Evic                                           === \n");
	printf("\t=====                                 - Fahmi                                          === \n");
	printf("\t=====                                 - Ibrahim                                        === \n");
	printf("\t========================================================================================== \n\n");
	printf("\t=====                                  PANDUAN                                         === \n");
	printf("\t===========================================================================================\n");
	printf("\t=====  1. Aplikasi ini dapat Membuat, Membuka, dan Mengedit File                       === \n");
	printf("\t=====  2. Pada setiap proses akan ditemui beberapa shortcut                            === \n");
	printf("\t=====     Ctrl + S, untuk save                                                         === \n");
	printf("\t=====     Ctrl + Q, untuk quit                                                         === \n");
	printf("\t=====  3. Backspace untuk menghapus karakter                                           === \n");
	printf("\t=====  4. Enter untuk baris baru                                                       === \n");
	printf("\t=====  5. Aplikasi ini juga dapat melakukan perubahan tema                             === \n");
	printf("\t========================================================================================== \n\n");
	system("pause");
}

void loading()
{
	int i,j;
	
	system("cls");
	printf("\n");
	printf("\t=========================================================================================  \n\n");
	printf("\t  ||||       |||   |||      |||  |||     |||  |||||||||                |||   ||||||||||    \n"); 
	printf("\t  ||||||     |||   |||      |||   |||   |||      |||                   |||   |||           \n");
	printf("\t  ||| |||    |||   |||      |||    ||| |||       |||                   |||   |||           \n");
	printf("\t  |||  |||   |||   |||      |||     |||||        |||                   |||   |||           \n");
	printf("\t  |||   |||  |||   |||      |||      |||         |||                   |||   ||||||||||    \n");
	printf("\t  |||    ||| |||   |||      |||     |||||        |||           |||     |||          |||    \n");
	printf("\t  |||     ||||||   |||      |||    ||| |||       |||           |||     |||          |||    \n");
	printf("\t  |||      |||||   |||      |||   |||   |||      |||           |||     |||          |||    \n");
	printf("\t  |||       ||||   ||||||||||||  |||     |||     |||     |||   |||||||||||   ||||||||||    \n\n");
	printf("\t========================================================================================== \n");
	printf("\t=====                                   TEXT EDITOR                                    === \n");
	printf("\t========================================================================================== \n\n");
	printf("\t                                       PLEASE WAIT . . .                                   \n\n");
	Sleep(800);
	printf("\t                                         >>> 3 <<<                                         \n\n");
	Sleep(1000);
	printf("\t                                         >>> 2 <<<                                         \n\n");
	Sleep(1000);
	printf("\t                                         >>> 1 <<<                                         \n\n");
	Sleep(1000);
	system("cls");
}

void border()
{
	int brs = MAX_ROWS;
	int klm = MAX_COLUMNS;
	
	// Margin Kanan
	for(brs = 0; brs < MAX_ROWS; brs++)
	{	
		gotoxy(brs,klm);
		printf(" |");	
	}
	
	// Margin Bawah
	for(klm = 0; klm <= MAX_COLUMNS; klm++)
	{	
		gotoxy(brs,klm);
		printf("-");	
	}
	printf("-");
	gotoxy(0,0);	
}