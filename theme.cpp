#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "theme.h"

void themes()
{
	int pilihan;
	char ulang = 'T', status = 'T';
	
	while(1)
	{
		printf("\n");
		printf("\t ===============================\n");
		printf("\t | Pilih Tema Yang Diinginkan: |\n");
		printf("\t | 1.Bright Theme              |\n");		
		printf("\t | 2.Dark Theme                |\n");
		printf("\t ===============================\n");	
		printf("\t Pilihan Kamu: ");
		scanf("%d", &pilihan);
		printf("\n");
		
		switch (pilihan)
		{
			case 1:
			{
				system("color F9");
				printf("\t Apakah kamu yakin menggunakan tema ini? (Y/T)\n");
				printf("\t Pilihan Kamu: ");
				ulang = toupper(getche());
				printf("\n\n");
				if (ulang == 'Y')
				{
					printf("\t Bright Theme Berhasil Digunakan!\n");
					printf("\t Tekan Enter Untuk Kembali!");
					(getche());
					system("cls");
					status = 'Y';
					break;
				}else{
					system("Color 0F");
					system("cls");
					printf("\t Kembali Ke Tema Default\n");
				}
				break;
			}
			
			case 2:
			{
				system("color 0F");
				printf("\t Apakah kamu yakin menggunakan tema ini? (Y/T)\n");
				printf("\t Pilihan Kamu: ");
				ulang = toupper(getche());
				printf("\n\n");
				if (ulang == 'Y')
				{
					printf("\t Dark Theme Berhasil Digunakan!\n");
					printf("\t Tekan Enter Untuk Kembali!");
					(getche());
					system("cls");
					status = 'Y';
					break;
				}else{
					system("Color 0F");
					system("cls");
					printf("\t Kembali Ke Tema Default\n");
				}
				break;
			}
		}
		
		if (status == 'Y')
		{
			break;
		}
	}
}