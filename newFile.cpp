#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "text.h"

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void newFile(){
// char S[sMax];
//
// gotoxy(33,4);printf("TEXT EDITOR");
// gotoxy(9,7);printf("---------------------------------------------------------------\n");
// gotoxy(9,9);printf("---------------------------------------------------------------\n");
// gotoxy(9,11);printf("---------------------------------------------------------------\n");
// gotoxy(9,13);printf("---------------------------------------------------------------\n");
// gotoxy(9,15);printf("---------------------------------------------------------------\n");
// gotoxy(9,17);printf("---------------------------------------------------------------\n");
// gotoxy(9,19);printf("---------------------------------------------------------------\n");
// gotoxy(9,21);printf("---------------------------------------------------------------\n");
// gotoxy(9,13);printf("---------------------------------------------------------------\n");
// 
// gotoxy(9,6);
// gets(S);

    FILE *fp;
    char in,fin[40],a;

    printf("Nama File :"); fflush(stdin);
    gets(fin);
    printf("Pencet write:w\n read:r \n");
    scanf("%c",&a);

    if(a=='r'){
        fp=fopen(fin,"r");
        printf("==========ini ngeread file========");

        while ((in=getc(fp)) !=EOF){
               printf("%c",in);
               }
               fclose(fp);
    }
    else if(a=='w'){
        fp=fopen(fin,"w");

        printf("=========ini buat nulis=====");
        printf("kalo mau save pencet ctrl+z\n");

        while ((in=getchar())!=EOF){
            putc(in,fp);
        }
        fclose(fp);
    }

    getch();

//    return 0;
}
