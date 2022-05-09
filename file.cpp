#include <stdio.h>
#include <windows.h>
#include "input.h"
#include "file.h"

void save(list L)
{
	char namaFile[25];
	address P;
	FILE *file;
	
	P = Head(L);
	printf("Nama file : ");
	scanf("%s", &namaFile);
	
	file = fopen(namaFile, "w");
	
	while(P != NULL)
	{
		fprintf(file, "%c", Info(P));
		P = Next(P);
	}
	fclose(file);
}

void fileToList(list *L)
{
	FILE *file;
	address P;
	int baris = 0, kolom = 0;
	char ch;
	
	file = fopen("tes.txt", "r");
	while(!feof(file))
	{
		ch = fgetc(file);
		if(ch == -1){
			break;
		}
		P = Alokasi(ch, baris, kolom);
		normal_input(*(&L), P, &baris, &kolom);
	}
	fclose(file);
}

void tampil_list(list L)
{
	address P;
	
	P = Head(L);
	
	printf("\n");
	while(P != NULL)
	{
		printf("%c", Info(P));
		P = Next(P);
	}
}

void lastCursor(int *row, int *col){
	POINT p;
	if(GetCursorPos(&p)){
		*row = p.x;
		*col = p.y;
	}
}

void modify(list *L)
{
	int baris, kolom;
	fileToList(&(*L));
	lastCursor(&baris, &kolom); // hanya pengantar sebelum kursor ada
	input_keyboard(&(*L), baris, kolom);
}
