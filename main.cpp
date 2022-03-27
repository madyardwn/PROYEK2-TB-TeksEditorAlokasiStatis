#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

#include "insert.h"
#include "design.h"

int main() 
{
	int pilihan;
	char text_editor[MAX_ROWS][MAX_COLUMNS];
	
	while(1)
	{
		memset(text_editor, 0, sizeof(text_editor));
		pilihan = 0;
		
		printf("===============================================================================================================\n");
		printf("===============|                              >>>>>  MENU  <<<<<                               |===============\n");
		printf("===============================================================================================================\n\n");
		printf("  1. Create Text\n");
		printf("  2. Exit\n\n");
		printf("===============================================================================================================\n");
		printf("===============|                      SILAHKAN PILIH MENU YANG DIINGINKAN                      |===============\n");
		printf("===============================================================================================================\n\n");
		printf("Pilihan Kamu: ");
		scanf("%d", &pilihan);
		printf("\n");
		fflush(stdin);
		
		switch(pilihan)
		{
			case 1:
			{
				loading();
				Insert(text_editor);
				system("cls");
				
				int baris = 0;
				int kolom = 0;
				
<<<<<<< HEAD
=======
				printf("Hasil Ketikkan\n\n");
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
			    for (; baris <= MAX_ROWS-1; baris++)
				{
			    	for(; kolom <= MAX_COLUMNS-1; kolom++){
			    		printf("%c",text_editor[baris][kolom]);
					}
					printf("\n");
					kolom = 0;
				}
				
<<<<<<< HEAD
				printf("\n");
=======
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
				clearscreen();
				
				break;
				
			}
			
			case 2:
			{
				return 0;
				break;
			}
			
			case 3:
			{
				break;
			}
			
			case 4:
			{
				break;
			}
			
			case 5:
			{
				break;
			}
			
			case 6:
			{
				break;
			}
			
			case 7:
			{
				return 0;
			}
			
			default:
			{
				system("cls");
				printf("Pilihan Menu Tidak Tersedia!\n\n");
				break;
			}
		}
	}
}