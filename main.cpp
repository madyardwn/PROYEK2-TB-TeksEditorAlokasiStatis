#include <iostream>
#include<fstream>
#include<iomanip>
#include "text.h"
#include <windows.h>
#include <conio.h>


void gotoxy(); //gotoxy untuk ngatur posisi output

//main driver
int main(){
	
	//kamus lokal
	char menu;
	char pilih;
	char S[sMax];
	
	//pemanggil procedure dan function
	mainmenu:
	mainmenu();
//	menu=getch();
	
	//switchcase main menu
	printf("\nPilih : ");
	scanf("%d", &pilih);
	switch (pilih){
		case 1 : 
			system("cls");
			newFile();
//			gotoxy(9,6);
//			gets(S);
//			system("cls");
//			goto menu;
			break;
		
		case 2 : 
			printf("open");
			break;
		
		
	}
}
