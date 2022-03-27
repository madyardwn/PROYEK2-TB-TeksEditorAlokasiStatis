#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

#include "design.h"
<<<<<<< HEAD
=======
#include "insert.h"
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)

void gotoxy(int baris,int kolom)
{
	COORD coord;
	
    coord.X = kolom;
    coord.Y = baris;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
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

<<<<<<< HEAD
=======
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

>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
void clearscreen(){
	printf("\nTekan Apapun Untuk Kembali!");
	getch();
	system("cls");
}