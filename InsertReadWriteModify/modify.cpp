#include "OREW.h"
#include "cursorWrite.h"

void modify(){
	char arr[ROWS][COLS];
	FILE *fp;
	char ch;
	short baris = 0;
	short kolom = 0;
	
	fp = fopen("tes.txt", "r+");
	while(!feof(fp)){
        ch = fgetc(fp);
    	if(ch == '\n'){
    		arr[baris][kolom] = ch;
    		baris++;
    		kolom = 0;
		}else{
	        arr[baris][kolom] = ch;
	        kolom++;	
		}
    }
    arr[baris][kolom] = '\0';
	fclose(fp);
	
	for(baris = 0; baris < ROWS; baris++){
		for(kolom = 0; kolom < COLS; kolom++){
			if(arr[baris][kolom] == '\0'){
            	break;
        	}
			printf("%c", arr[baris][kolom]);
		}
		if(arr[baris][kolom] == '\0'){
            break;
        }
	}
	LastCursor(baris, kolom);
	insert(arr, baris, kolom--);
}