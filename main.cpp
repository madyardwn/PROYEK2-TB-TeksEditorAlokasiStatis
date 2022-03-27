#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

#include "insert.h"
#include "design.h"
#include "theme.h"
#include "FileHandler.h"

int main() 
{
	
	char text_editor[MAX_ROWS][MAX_COLUMNS];
	int pilihan;
	while(1)
	{
		memset(text_editor, 0, sizeof(text_editor));
		pilihan = 0;
		system("cls");
		printf("===============================================================================================================\n");
		printf("===============|                              >>>>>  MENU  <<<<<                               |===============\n");
		printf("===============================================================================================================\n\n");
		printf("  1. Panduan\n"); // belum
		printf("  2. Membuat File\n"); 
		printf("  3. Daftar File\n");
		printf("  4. Duplicate File\n");
		printf("  5. Find and Replace\n");
		printf("  6. Jumlah Kata\n");
		printf("  7. Theme\n");
		printf("  8. Exit\n\n");
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
				break;	
			}
			
			case 2:
			{
				loading();				
				system("cls");
				Insert(text_editor);
				saveToFile(text_editor);
				break;
			}
			
			case 3:
			{
				ListFile();
				modify(text_editor);
				break;
			}
			
			case 4:
			{
				ListFile();
				duplicate();
				system("pause");
				break;
			}
			
			case 5:
			{
				ListFile();
				finrep();
				system("pause");
				break;
			}
			
			case 6:
			{
				system("cls");
				ListFile();
				jumlah_kata();
				system("pause");
				break;
			}
			
			case 7:
			{
				system("cls");
				themes();
				break;
			}
			
			case 8:
			{
				return 0;
				break;
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
