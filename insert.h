#ifndef insert_H
#define insert_H

#include "design.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define MAX_ROWS 40
#define MAX_COLUMNS 80

void Insert(char arr[MAX_ROWS][MAX_COLUMNS]);
bool Cek_Input(char ch);
void Input_Handling(int *baris, int *kolom, char *ch, char arr[MAX_ROWS][MAX_COLUMNS]);

#endif