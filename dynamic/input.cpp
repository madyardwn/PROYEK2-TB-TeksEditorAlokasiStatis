#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "input.h"

address Alokasi(char ch)
{
	address P;
	P = (address) malloc (sizeof(element_list));
	if (P != NULL)
	{
		Prev(P) = NULL;
		Info(P) = ch;
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
	bool validasi_input;
	address P;
	
	while (1)
	{
		ch = getch();
		P = Alokasi(ch);
		
		// ctrl + q untuk keluar text editor
		if (ch == 17)
		{
			break;
		}
		
		// Cek Validasi Input
		validasi_input = cek_input(ch);
		if (validasi_input != true)
		{
			normal_input(*(&L), P);
		}else{
			handling_input(*(&L), P);
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

void normal_input(list *L, address P)
{
	// Kondisi Awal Menulis
	if (Head(*L) == NULL and Current (*L) == NULL and Tail(*L) == NULL)
	{
		Head(*L) = P;
		Tail(*L) = P;
		Current(*L) = P;
		printf("%c", Info(Current(*L)));
	}else
	
	// Menulis di awal baris dan kolom 
	if (Current(*L) == Head(*L))
	{
		Next(Head(*L)) = P;
		Prev(P) = Head(*L);
		Current(*L) = P; 
		if (Tail(*L) == Head(*L))
		{
			Tail(*L) = P;
		}
		printf("%c", Info(Current(*L)));
	}else
	
	// Menulis di akhir baris dan kolom
	if (Current(*L) == Tail(*L))
	{
		Next(Tail(*L)) = P;
		Prev(P) = Tail(*L);
		Tail(*L) = P;
		Current(*L) = P;
		printf("%c", Info(Current(*L)));
	}else
	
	// Menulis di suatu baris dan kolom
	{
		Next(P) = Next(Current(*L));
		Prev(Next(Current(*L))) = P;
		Next(Current(*L)) = P;
		Prev(P) = Current(*L);
		Current(*L) = P;
		printf("%c", Info(Current(*L)));
	}
}

void handling_input(list *L, address P)
{
	// Backspace
	if (Info(P) == 8)
	{
		// Modul Backspace
	}
	
	// Enter
	if (Info(P) == 13)
	{
		// Modul Enter
	}
	
	// Arrow
	if (Info(P) == -32)
	{
		// Modul Arrow
	}
	
	// Tab
	if (Info(P) == 9)
	{
		// Modul Tab
	}
	
	// ESC
	if (Info(P) == 27)
	{
		// Modul ESC
	}
		
}

void tampil_list(list L)
{
	system("cls");
	printf("Hasil Tulisan\n\n");
	while(Head(L) != NULL)
	{
		printf("%c", Info(Head(L)));
		Head(L) = Next(Head(L));
	}
}