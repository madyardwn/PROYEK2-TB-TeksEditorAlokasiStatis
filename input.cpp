#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include "input.h"
#include "design.h"

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
	address P;
	P = Alokasi(NULL);
	
	Head(*L) = P;
	Current(*L) = P;
	Tail(*L) = P;
}

void input_keyboard(list *L)
{
	// Kamus Data
	char ch;
	int baris = 0, kolom = 0;
	bool validasi_input;
	address P;
	address Q;
	
	gotoxy(28,0);
	printf("Baris: %d\n", baris+1); 
	printf("Kolom: %d", kolom+1);
	gotoxy(baris,kolom);
	
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
		if (validasi_input != true)
		{
			P = Alokasi(ch);
			if (P != NULL)
			{
				normal_input(*(&L), P, &Q, &baris, &kolom);
				gotoxy(28,0);
				printf("                         \n");
				printf("                         ");
				gotoxy(28,0);
				printf("Baris: %d\n", baris+1); 
				printf("Kolom: %d", kolom+1);
				gotoxy(baris,kolom);
			}else{
				Beep(1000,50);
			}
		}else
		
		// Jika perlu di handling, maka input di handle terlebih dahulu
		{
			handling_input(*(&L), ch, &baris, &kolom);
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

void normal_input(list *L, address P, address *Q, int *baris, int *kolom)
{
	// Linked List
	if (Next(Current(*L)) != NULL)
	{
		Next(P) = Next(Current(*L));
		Prev(Next(Current(*L))) = P;
		Next(Current(*L)) = P;
		Prev(P) = Current(*L);
		Current(*L) = P; 
	}else{
		Next(Current(*L)) = P;
		Prev(P) = Current(*L);
		Tail(*L) = P;
		Current(*L) = P;
	}
	
	// Tampil Layar
//	system("cls");
//	P = Next(Head(*L));
//	
//	while(P != NULL)
//	{
//		printf("%c", Info(P));
//		if (Info(P) == NULL)
//		{
//			printf("\n");
//		}
//		P = Next(P);
//	}
	
	P = Current(*L);
	while(P != NULL)
	{
		if (Info(P) == NULL)
		{
			break;
		}
		printf("%c", Info(P));
		P = Next(P);
	}

	*kolom = *kolom + 1;
	gotoxy(*baris,*kolom);
}

void handling_input(list *L, char ch, int *baris, int *kolom)
{
	// Backspace
	if (ch == 8)
	{
		// Modul Backspace
	}else
	
	// Enter
	if (ch == 13)
	{
		enter(*(&L), ch, *(&baris), *(&kolom));
	}else
	
	// Arrows
	if (ch == -32)
	{
		arrows(*(&L), ch, *(&baris), *(&kolom));
	}else
	
	// Tab
	if (ch == 9)
	{
		// Modul Tab
	}else
	
	// ESC
	if (ch == 27)
	{
		// Modul ESC
	}
}

void arrows(list *L, char ch, int *baris, int *kolom)
{	
	address P;
	int count = 0;
	ch = getch();
	
	switch(ch)
	{
		// Up Arrow
		case 72:
		{
			P = Current(*L);
			if (P == Head(*L))
			{
				gotoxy(*baris,*kolom);
				break;
			}
			
			// Hitung Posisi dari NULL
			*kolom = 0;
			while(Info(P) != NULL)
			{
				P = Prev(P);
				count = count + 1;
			}
			P = Prev(P);
			
			if (P == NULL)
			{
				*kolom = count;
				Current(*L) = P;
				gotoxy(*baris,*kolom);
				break;
			}
			
			if (Info(P) == NULL)
			{
				Current(*L) = P;
			}else{
				while(Info(P) != NULL)
				{
					P = Prev(P);
				}
				
				// Ubah Posisi
				for (int i=0; i < count; i++)
				{
					P = Next(P);
					*kolom = *kolom + 1;
					if (Info(P) == NULL)
					{
						Current(*L) = Prev(Current(*L));
						*kolom = *kolom - 1;
						break;
					}	
				}
				Current(*L) = P;
			}
			*baris = *baris - 1;
			gotoxy(*baris,*kolom);
			break;
		}
		
		// Down Arrow
		case 80:
		{
			P = Current(*L);
			if (P == Tail(*L))
			{
				gotoxy(*baris,*kolom);
				break;
			}
			
			// Hitung Posisi dari NULL
			*kolom = 0;
			while(Info(P) != NULL)
			{
				P = Prev(P);
				count = count + 1;
			}
			P = Next(P);
			
			if (Info(P) == NULL)
			{
				Current(*L) = P;
			}else{
				while(Info(P) != NULL)
				{
					P = Next(P);
				}
				
				// Ubah Posisi
				for (int i=0; i < count; i++)
				{
					if (Next(P) != NULL)
					{
						P = Next(P);
						Current(*L) = P;
						*kolom = *kolom + 1;
						if (Info(P) == NULL)
						{
							Current(*L) = Prev(Current(*L));
							*kolom = *kolom - 1;
							break;
						}	
					}else{
						Current(*L) = P;
						break;
					}
				}
			}
			*baris = *baris + 1;
			gotoxy(*baris,*kolom);
			
			break;
		}
		
		// Right Arrow
		case 77:
		{
			P = Current(*L);
			if (Next(P) != NULL)
			{
				Current(*L) = Next(P);
				*kolom = *kolom + 1;
				if (Info(Current(*L)) == NULL)
				{
					*kolom = 0;
					*baris = *baris + 1;
				}
				gotoxy(*baris,*kolom);
			}
			break;
		}
		
		// Left Arrow
		case 75:
		{
			P = Current(*L);
			if (Prev(P) != NULL)
			{
				Current(*L) = Prev(P);
				*kolom = *kolom - 1;
				if (Info(P) == NULL)
				{
					P = Prev(P);
					while(Info(P) != NULL)
					{
						P = Prev(P);
					}
					*kolom = 0;
					P = Next(P);
					while(Info(P) != NULL)
					{
						P = Next(P);
						*kolom = *kolom + 1;
					}
					*baris = *baris - 1;
				}
				gotoxy(*baris,*kolom);
			}
			break;
		}
		
		default:
		{
			break;
		}
	}
}

void enter(list *L, char ch, int *baris, int *kolom)
{
	address P;
	
	P = Alokasi(NULL);
	if (Next(Current(*L)) != NULL)
	{
		Prev(P) = Current(*L);
		Next(P) = Next(Current(*L));
		Prev(Next(Current(*L))) = P;
		Next(Current(*L)) = P;
		Current(*L) = P;
	}else{
		Next(Current(*L)) = P;
		Prev(P) = Current(*L);
		Current(*L) = P;
	}
	
	// Tampil Layar
	system("cls");
	P = Next(Head(*L));
	
	while(P != NULL)
	{
		printf("%c", Info(P));
		if (Info(P) == NULL)
		{
			printf("\n");
		}
		P = Next(P);
	}
	*baris = *baris + 1;
	*kolom = 0;
	gotoxy(*baris,*kolom);
}
            
void tampil_list(list L)
{
	system("cls");
	printf("Hasil Tulisan\n\n");
	
	address P;
	P = Next(Head(L));
	
	while(P != NULL)
	{
		printf("%c", Info(P));
		if (Info(P) == NULL)
		{
			printf("\n");
		}
		P = Next(P);
	}
}