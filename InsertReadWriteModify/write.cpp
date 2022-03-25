#include "OREW.h"

void writeToFile(char arr[ROWS][COLS]){
	FILE *fp;
	fp = fopen("tes.txt", "w");
	int baris = 0; 
	int kolom = 0;
    for (baris = 0; baris < ROWS; baris++) {
        for (kolom = 0; kolom < COLS; kolom++) {
            if(arr[baris][kolom] == '\0'){
                break;
            }
            fprintf(fp, "%c", arr[baris][kolom]);
        }
        if(arr[baris][kolom] == '\0'){
            break;
        }
    }
    fclose(fp);
}	