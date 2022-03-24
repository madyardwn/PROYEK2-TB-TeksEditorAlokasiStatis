#include "insert.h"

int main(){
	char arr[ROWS][COLS];
	Insert(arr);
	printf("\n\nHasil ketikan :\n");
	
	int baris = 0; 
	int kolom = 0;
    for (baris = 0; baris < ROWS; baris++) {
        for (kolom = 0; kolom < COLS; kolom++) {
            if(arr[baris][kolom] == '\0'){
                break;
            }
            printf("%c", arr[baris][kolom]);
        }
        if(arr[baris][kolom] == '\0'){
            break;
        }
    }
    return 0;
}