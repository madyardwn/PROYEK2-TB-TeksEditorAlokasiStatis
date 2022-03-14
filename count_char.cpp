#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "count_char.h"

void jumlah_karakter()
{
	FILE *fp;
	char in,fin[40];
	int jumlah_karakter = 0;
	fflush(stdin);
	
	printf("Nama File: "); 
    gets(fin); 
	fflush(stdin);
	
	printf("\nFile yang dibuka: %s\n\n", fin);
	fp=fopen(fin,"rt");
	
	while ((in=getc(fp)) !=EOF)
	{
       if (in != ' ')
	   {
			jumlah_karakter++;
	   }
    }
    fclose(fp);
       
	printf("Jumlah karakter pada file tersebut sebanyak: %d karakter", jumlah_karakter);
}

void jumlah_kata()
{
	FILE *fp;
	char in,fin[40];
	int jumlah_kata = 0;
	fflush(stdin);
	
	printf("Nama File: "); 
    gets(fin); 
	fflush(stdin);
	
	printf("\nFile yang dibuka: %s\n\n", fin);
	fp=fopen(fin,"rt");
	
	while ((in=getc(fp)) !=EOF)
	{
       if (in == ' ')
	   {
			jumlah_kata++;
	   }
    }
    jumlah_kata++;
    fclose(fp);
       
	printf("Jumlah kata file tersebut sebanyak: %d Kata\n\n", jumlah_kata);	
}