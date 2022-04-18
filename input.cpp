#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include "input.h"
#include "design.h"

address Alokasi(char ch, int baris, int kolom)
{
	address P;
	P = (address) malloc (sizeof(element_list));
	if (P != NULL)
	{
		Prev(P) = NULL;
		Info(P) = ch;
		Baris(P) = baris;
		Kolom(P) = kolom;
		Next(P) = NULL;
		
		return P;
	}else{
		return NULL;
	}
}

void create_text_editor(list *L)
{
	Head(*L) = NULL;
	Current(*L) = NULL;
	Tail(*L) = NULL;
}

void input_keyboard(list *L)
{
	// Kamus Data
	char ch;
	int baris = 0, kolom = 0;
	bool validasi_input;
	address P;
	
	while (1)
	{
		ch = getch();
		
		// ctrl + q untuk keluar text editor
		if (ch == 17)
		{
			break;
		}
		
		// Cek Validasi Input
		validasi_input = cek_input(ch);
		
		// Jika tidak perlu di handling, maka input normal
		if (validasi_input != true and (baris < MAX_ROWS-1 or kolom < MAX_COLUMNS))
		{
			// Cek Kolom
			if (kolom == MAX_COLUMNS)
			{
				kolom = 0;
				baris = baris + 1;
			}
			gotoxy(baris,kolom);
			
			P = Alokasi(ch, baris, kolom);
			normal_input(*(&L), P, &baris, &kolom);
		}else
		
		// Jika perlu di handling, maka input di handle terlebih dahulu
		if (baris < MAX_ROWS-1 or kolom < MAX_COLUMNS)
		{
			handling_input(*(&L), ch, &baris, &kolom);
		}else
		
		// Jika sudah melebihi batas baris dan kolom, maka input dihentikan
		{
			Beep(1000,50);
		}
	}
}

bool cek_input(char ch)
{
	switch(ch)
	{	
		// Backspace
		case 8:
		{
			return true;
			break;
		}
		
		// Enter
		case 13:
		{
			return true;
			break;
		}
		
		// Arrow
		case -32:
		{
			return true;
			break;
		}
		
		// Tab
		case 9:
		{
			return true;
			break;
		}
		
		// ESC
		case 27:
		{
			return true;
			break;
		}
		
		// Normal
		default:
		{
			return false;
			break;
		}	
	}		
}

void normal_input(list *L, address P, int *baris, int *kolom)
{	
	// Kondisi Awal Menulis
	if (Head(*L) == NULL and Current (*L) == NULL and Tail(*L) == NULL)
	{
		// Linked List
		Head(*L) = P;
		Tail(*L) = P;
		Current(*L) = P;
		
		// Tampil Layar
		printf("%c", Info(Current(*L)));
	}else
	
	// Menulis di awal baris dan kolom 
	if (Current(*L) == Head(*L))
	{
		// Linked List
		Next(Head(*L)) = P;
		Prev(P) = Head(*L);
		Current(*L) = P; 
		if (Tail(*L) == Head(*L))
		{
			Tail(*L) = P;
		}
		
		// Tampil Layar
		printf("%c", Info(Current(*L)));
	}else
	
	// Menulis di akhir baris dan kolom
	if (Current(*L) == Tail(*L))
	{
		// Linked List
		Next(Tail(*L)) = P;
		Prev(P) = Tail(*L);
		Tail(*L) = P;
		Current(*L) = P;
		
		// Tampil Layar
		printf("%c", Info(Current(*L)));
	}else
	
	// Menulis di suatu baris dan kolom
	{
		// Linked List
		Next(P) = Next(Current(*L));
		Prev(Next(Current(*L))) = P;
		Next(Current(*L)) = P;
		Prev(P) = Current(*L);
		Current(*L) = P;
		
		// Tampil Layar
		printf("%c", Info(Current(*L)));
	}
	
	*kolom = *kolom + 1;
}

void handling_input(list *L, char ch, int *baris, int *kolom)
{
	// Backspace
	if (ch == 8)
	{
		// Modul Backspace
	}
	
	// Enter
	if (ch == 13)
	{
		// Modul Enter
	}
	
	// Arrows
	if (ch == -32)
	{
		arrows(*(&L), ch, *(&baris), *(&kolom));
	}
	
	// Tab
	if (ch == 9)
	{
		// Modul Tab
	}
	
	// ESC
	if (ch == 27)
	{
		// Modul ESC
	}
}

void arrows(list *L, char ch, int *baris, int *kolom)
{	
	address P;
	ch = getch();
	
	switch(ch)
	{
		// Up Arrow
		case 72:
		{
			// Jika berada pada baris paling awal
			if (*baris == 0)
			{
				gotoxy(*baris,*kolom);
			}else
			
			if (*baris != 0)
			{
				P = Current(*L);
				for (int i = *kolom; i >= 0; i--)
				{
					P = Prev(P);
				}
			}
			break;
		}
		
		// Down Arrow
		case 80:
		{
			break;
		}
		
		// Right Arrow
		case 77:
		{
			break;
		}
		
		// Left Arrow
		case 75:
		{
			break;
		}
		
		default:
		{
			break;
		}
	}
}

void tampil_list(list L)
{
	system("cls");
	printf("Hasil Tulisan\n\n");
	
	address P;
	P = Head(L);
	
	while(P != NULL)
	{
		printf("%c", Info(P));
		P = Next(P);
		if (Baris(P) != 0 and Kolom(P) == 0)
		{
			printf("\n");
		}
	}
}