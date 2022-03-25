#ifndef insert_H
#define insert_H

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ROWS 5
#define COLS 20 

void gotoxy(short x, short y);
void Insert(char arr[ROWS][COLS], short baris, short kolom);
void modify();
void writeToFile(char arr[ROWS][COLS]);

#endif