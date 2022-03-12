#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <string>
#include "delete.h"

void delete_rows (string mas[]) 
{
	int row1,row2;
	printf("Masukkan baris yang ingin di hapus \n");
	printf("Dari baris : ");
	scanf("%d", &row1);
	row1=row1-1;
	
	pritnf("\n Sampai Baris : ");
	scanf("%d", &row2);
	row2=row2-1;
	
	for ( row1 ; row1<N-row1 ; row1++) 
	{
		row2++;
		mas[row1]=mas[row2];
	}
	ofstream file2("FF.txt",ios::in); 
	for (int i=0 ; i<=N; i++) 
	{
		file2<< mas[i]<<endl;
	}
}
