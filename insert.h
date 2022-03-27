#ifndef insert_H
#define insert_H

#include "design.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

<<<<<<< HEAD
#define MAX_ROWS 5
#define MAX_COLUMNS 10
=======
#define MAX_ROWS 40
#define MAX_COLUMNS 80
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)

void Insert(char arr[MAX_ROWS][MAX_COLUMNS]);
bool Cek_Input(char ch);
void Input_Handling(int *baris, int *kolom, char *ch, char arr[MAX_ROWS][MAX_COLUMNS]);
bool Cek_Kolom(int baris, int kolom, char arr[MAX_ROWS][MAX_COLUMNS]);

#endif