#include "OREW.h"
#include "cursorWrite.h"

void insert(char arr[ROWS][COLS], short baris, short kolom){
    char ch;
    gotoxy(kolom, baris);
    
    // khusus edit untuk menghapus elemen '\0'
	if(baris != 0 || kolom != 0){
		printf("\b \b");
	    arr[baris][kolom] = '\0';
	    kolom--;	
	}
	
    while(1){
		ch = getch();
		if (ch == 'q')
        {
            arr[baris][kolom] = '\0';
            break;
        }
        // backspace 
        else if (ch == 8 || ch == 127)
        {
			if(baris == 0 && kolom == 0){
				continue;
			}else if(kolom == 0){
           		//printf("\b \b");
                kolom = COLS-1;
                baris--;
                gotoxy(kolom, baris);
                arr[baris][kolom] = '\0';
            }else{
                printf("\b \b");
                arr[baris][kolom] = '\0';
                kolom--;
        	}
    	}
        // membaca enter
        else if(ch == 13){
        	if(baris == ROWS-1){
        		continue;
			}else{
				for (; kolom < COLS-1; kolom++) {
                	arr[baris][kolom] = 32;
            	}
            	arr[baris][kolom] = '\n';
            	baris++;
            	kolom = 0;
            	printf("\n");
			}
        }else{
            // apabila menyentuh margin
            if(kolom == COLS-1){
            	if(baris == ROWS-1){
            		continue;
				}
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
    // otomatis write to file
    // belum decision
    writeToFile(arr);
}