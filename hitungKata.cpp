#include <iostream>
#include<fstream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){


	FILE *fp;
	char in, namafile[10], text;
	int jumlah_kata = 0;
	
	
	printf("Nama file yang mau dibuka : "); fflush(stdin);
	gets(namafile);
	
	printf("File yang dibuka: %s\n\n", namafile);
	fp=fopen(namafile,"rt");
	if(fp==NULL){
		printf("File yang dipilih tidak ada!!");
	}else{
	
	
	//memunculkan isi file
	printf("Isi file : \n");
	while ((text=getc(fp)) !=EOF){
               printf("%c",text);
               }
  //             fclose(fp);
	
	
	
	//menghitung kata
	fp=fopen(namafile,"rt");
	if(fp==NULL){
		//printf("File yang dipilih tidak ada!!");
	}
	while ((in=getc(fp)) !=EOF)
	{
       if (in == ' ')
	   {
			jumlah_kata++;
	   }
    }
    jumlah_kata++;
    fclose(fp);
       

	printf("\n\n Jumlah kata file tersebut sebanyak: %d Kata\n\n", jumlah_kata);
}
}

