#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main(){


	char sfile, nfile[10], nb[10];
	
	printf("Nama file yang akan diduplicate : "); fflush(stdin);
	gets(nfile);
	ifstream inputFile(nfile); //mengambil file mana yg mau di duplicate
	
	
	printf("Nama file yang sudah diduplicate : "); fflush(stdin);
	gets(nb);
	ofstream outFile(nb); //keluaran duplicate file
	
	while(inputFile.get(sfile)){
		outFile.put(sfile);
	}
	if(outFile.put(sfile)){
		printf("file berhasil diduplicate");
	}else{
		printf("gagal duplicate");
	}
	return 0;
}
