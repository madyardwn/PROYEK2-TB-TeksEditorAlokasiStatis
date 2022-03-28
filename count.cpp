#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "design.h"
#include "insert.h"

//Modul Menghitung Jumlah Karakter
int count_char(char arr[MAX_ROWS][MAX_COLUMNS])
{
	int jumlah_char = 0;
	
	for (int baris = 0; baris < MAX_ROWS-1; baris++)
	{	
		for (int kolom = 0; kolom < MAX_COLUMNS-1; kolom++)
		{
			if(arr[baris][kolom] == NULL or arr[baris][kolom] == 32)
			{
				jumlah_char = jumlah_char;
			}else{
				jumlah_char = jumlah_char + 1;
			}
		}
	}
	
	return jumlah_char;
}

//Modul Menampilkan informasi pada layar
void cursor_information(int baris, int kolom, char arr[MAX_ROWS][MAX_COLUMNS])
{
	int jumlah_char;
	jumlah_char = count_char(arr);
	
	gotoxy(baris,kolom);
	gotoxy(1,MAX_COLUMNS + 6);
	printf("=======================");
	gotoxy(2,MAX_COLUMNS + 6);
	printf("|      Informasi      |");
	gotoxy(3,MAX_COLUMNS + 6);
	printf("=======================");
	gotoxy(4,MAX_COLUMNS + 6);
	printf("                       ");
	gotoxy(4,MAX_COLUMNS + 6);
	printf(" Baris: %d", baris+1);
	gotoxy(5,MAX_COLUMNS + 6);
	printf("                       ");
	gotoxy(5,MAX_COLUMNS + 6);
	printf(" Kolom: %d", kolom+1);
	gotoxy(6,MAX_COLUMNS + 6);
	printf("                         ");
	gotoxy(6,MAX_COLUMNS + 6);
	printf(" Jumlah Karakter : %d", jumlah_char);
}