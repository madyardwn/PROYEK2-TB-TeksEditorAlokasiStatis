#ifndef OREW_H
#define OREW_H

#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ROWS 5
#define COLS 20 

void gotoxy(short x, short y);
void insert(char arr[ROWS][COLS], short baris, short kolom);
void modify();
void read();
void writeToFile(char arr[ROWS][COLS]);

#endif