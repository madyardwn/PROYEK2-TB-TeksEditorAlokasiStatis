#include "insert.h"

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void Insert(char arr[ROWS][COLS]){
    system("cls");
    char ch;
    gotoxy(1,1);
    int baris = 0;
    int kolom = 0;
    
    while(1){
        ch = getch();
        if(kolom == COLS && baris == ROWS){
            break;
        }
        if (ch == 'q')
        {
            arr[baris][kolom] = '\0';
            break;
            
        }
        // backspace 
        else if (ch == 8 || ch == 127)
        {
           if(kolom == 0){
                kolom = COLS;
                gotoxy(kolom, baris);
                baris--;
                arr[baris][kolom] = '\0';
                kolom--;
            }else{
                printf("\b \b");
                arr[baris][kolom] = '\0';
                kolom--;
            }
        }
        // membaca enter
        else if(ch == 13){
            for (; kolom < COLS-1; kolom++) {
                arr[baris][kolom] = 32;
            }
            arr[baris][kolom] = '\n';
            baris++;
            kolom = 0;
            printf("\n");
        }else{
            // apabila menyentuh margin
            if(kolom == COLS -1){
                arr[baris][kolom] = '\n';
                printf("%c", arr[baris][kolom]);
                baris++;
                kolom = 0;
                arr[baris][kolom] = ch;
                kolom++;
                printf("%c", ch);

            // tidak menyentuh margin
            }else{
                printf("%c", ch);
                arr[baris][kolom] = ch;
                kolom++;
            }
            
        }
    }
}