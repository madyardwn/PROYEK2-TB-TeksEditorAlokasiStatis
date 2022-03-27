#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "insert.h"
<<<<<<< HEAD
=======
#include "design.h"
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)

void Insert(char arr[MAX_ROWS][MAX_COLUMNS])
{
    system("cls");
    char ch;
    bool Validasi_Input;
    gotoxy(0,0);
    int baris = 0;
    int kolom = 0;
    
<<<<<<< HEAD
=======
    //Mengatur Tampilan
    border();
    
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
    // Menulis Pada Array
    while(1)
	{   
		// Input Keyboard
		fflush(stdin);
		ch = getch();
		if (ch == 'q'){
			break;
		}
		
		// Cek Input Handling
		Validasi_Input = Cek_Input(ch);
		
		if (Validasi_Input)
		{
			Input_Handling(&baris, &kolom, &ch, arr);	
		}
		
		if (baris < MAX_ROWS-1 or kolom <= MAX_COLUMNS-1)
		{
			if (kolom <= MAX_COLUMNS-1 and !Validasi_Input)
			{
				printf("%c", ch);
				arr[baris][kolom] = ch;
				kolom++;
			}else 
			
			if (kolom > MAX_COLUMNS-1 and baris < MAX_ROWS-1 and !Validasi_Input)
			{

				kolom = 0;
				baris++;
				gotoxy(baris,kolom);	
				printf("%c", ch);
				arr[baris][kolom] = ch;
				kolom++;
			}
			gotoxy(baris,kolom);
		}else{
			Beep(1000,50);
		}
	}
}

bool Cek_Input(char ch)
{
	switch(ch)
	{
<<<<<<< HEAD
=======
		// Null
		case 0:
		{
			return true;
			break;
		}
		
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
		// Backspace
		case 8:
		{
			return true;
			break;
		}
		
		// Enter
		case 13:
		{
			return true;
			break;
		}
		
		// Arrow
		case -32:
		{
			return true;
			break;
		}
		
<<<<<<< HEAD
=======
		// Tab
		case 9:
		{
			return true;
			break;
		}
		
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
		// Normal
		default:
		{
			return false;
			break;
		}	
	}		
}

bool Cek_Kolom(int baris, int kolom, char arr[MAX_ROWS][MAX_COLUMNS])
{
	for (; kolom <= MAX_COLUMNS-1; kolom++)
	{
		if (arr[baris][kolom] == NULL){
			return true;
		}
	}
	
	return false;
}

void Input_Handling(int *baris, int *kolom, char *ch, char arr[MAX_ROWS][MAX_COLUMNS])
{
<<<<<<< HEAD
	char temp = NULL;
	bool IsNull;
	
	// Backspace
	if (*ch == 8)
	{
		if (*kolom == 0 and *baris == 0)
		{
			if (arr[*baris][*kolom] != NULL){
				printf(" ");
			}
			*ch = NULL;
			arr[*baris][*kolom] = *ch;
		}else
		
		if (*kolom <= MAX_COLUMNS and *kolom != 0)
		{
			for (int i = *kolom; i <= MAX_COLUMNS; i++)
			{
				arr[*baris][i-1] = arr[*baris][i];
				if (i == MAX_COLUMNS){
					arr[*baris][i-1] = NULL;
				}
				gotoxy(*baris,i-1);
				if(arr[*baris][i-1] == NULL){
					printf(" ");
				}else{
					printf("%c", arr[*baris][i-1]);
				}
			}
			*kolom = *kolom - 1;
			
			if (*kolom == 0 and arr[*baris-1][MAX_COLUMNS-1] != NULL and arr[*baris][0] == NULL)
			{
				if (*baris != 0){
					*baris = *baris - 1;
					*kolom = MAX_COLUMNS;	
=======
	int brs = 0, klm = 0, klm_1 = 0, temp;
	bool status;
	
	// Null
	if (*ch == 0)
	{
		*ch = getch();
	}
	
	// Tab
	if (*ch == 9)
	{
		gotoxy(*baris,*kolom);
	}
	
	// Backspace
	if (*ch == 8)
	{		
		if (*kolom <= MAX_COLUMNS and *kolom != 0)
		{
			*kolom = *kolom - 1;
			brs = *baris;
			klm = *kolom;
			
			while (klm < MAX_COLUMNS)
			{
				gotoxy(brs,klm);
			
				//Ubah Array
				if ((klm + 1) != MAX_COLUMNS){
					arr[brs][klm] = arr[brs][klm+1];
				}else{
					arr[brs][klm] = NULL;
				}
				
				//Tampil Layar
				if (arr[brs][klm] == NULL){
					printf(" ");
				}else{
					printf("%c", arr[brs][klm]);	
				}	
				
				klm = klm + 1;
			}
			gotoxy(*baris,*kolom);
		}else
		
		if (arr[*baris][*kolom] == NULL and *baris < MAX_ROWS-1)
		{
			//Cek Baris Dibawah
			status = false;
			for(int i = *baris+1; i < MAX_ROWS; i++)
			{
				if (arr[i][0] != NULL){
					status = true;
					break;
				}
			}
			
			//Jika Seluruh Baris Dibawahnya Kosong
			if (!status)
			{
				if(*baris != 0)
				{
					brs = *baris;
					klm = *kolom;		
					gotoxy(*baris,*kolom);
					brs = *baris - 1;
					klm = *kolom;
					while (klm <= MAX_COLUMNS-1)
					{
						if (arr[brs][klm] == NULL){
							break;
						}
						klm = klm + 1;
					}
					*kolom = klm;
					*baris = brs;
				}else{
					gotoxy(*baris,*kolom);
				}
				
			//Jika Baris Dibawahnya Terdapat Yang Tidak Kosong		
			}else{
				brs = *baris;
				klm = *kolom;
				while (brs <= MAX_ROWS-1)
				{	
					if (klm == MAX_COLUMNS){
						klm = 0;
						brs = brs + 1;
					}
					
					gotoxy(brs,klm);
					
					//Ubah Array
					if (brs < MAX_ROWS-1){
						arr[brs][klm] = arr[brs+1][klm];
					}else{
						arr[brs][klm] = NULL;
					}
					
					//Tampil Layar
					gotoxy(brs,klm);
					if (arr[brs][klm] == NULL and brs != MAX_ROWS){
						printf(" ");
					}else{
						printf("%c", arr[brs][klm]);	
					}
					
					klm = klm + 1;
				}
			}
			gotoxy(*baris,*kolom);
		}else
		
		if (*kolom == 0 and *baris != 0 and arr[*baris+1][*kolom] != NULL)
		{
			//Cari Huruf Terakhir
			*baris = *baris - 1;
			*kolom = 0;
			while(*kolom < MAX_COLUMNS)
			{
				if (arr[*baris][*kolom] == NULL){
					break;
				}
				*kolom = *kolom + 1;
				gotoxy(*baris,*kolom);
			}
			if (*kolom == MAX_COLUMNS){
				*kolom = *kolom - 1;
			}
			brs = *baris;
			klm = *kolom;
			temp = 0;
		
			while (brs == *baris and klm <= MAX_COLUMNS)
			{
				if (klm == MAX_COLUMNS){
					brs = brs + 1;
					klm = 0;
				}else{
					
					gotoxy(brs,klm);
					
					//Ubah Array
					arr[brs][klm] = arr[brs+1][klm_1];
					if (arr[brs][klm] != NULL){
						temp = temp + 1;
						arr[brs+1][klm_1] = NULL;
					}
					
					//Tampil Layar
					if (arr[brs][klm] == NULL){
						printf(" ");
					}else{
						printf("%c", arr[brs][klm]);	
					}
					
					klm = klm + 1;
					klm_1 = klm_1 + 1;
				}
			}
			
			klm_1 = temp;
			while (klm < MAX_COLUMNS)
			{
				gotoxy(brs,klm);
			
				//Ubah Array
				if (klm_1 < MAX_COLUMNS){
					arr[brs][klm] = arr[brs][klm_1];
				}else{
					arr[brs][klm] = NULL;
				}
				
				//Tampil Layar
				if (arr[brs][klm] == NULL){
					printf(" ");
				}else{
					printf("%c", arr[brs][klm]);	
				}	
				
				klm = klm + 1;
				if (klm_1 < MAX_COLUMNS){
					klm_1 = klm + 1;
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
				}
			}
			gotoxy(*baris,*kolom);
		}else
			
<<<<<<< HEAD
		if (*kolom == 0 and *baris != 0)
		{
			if(arr[*baris][*kolom] != NULL){
				temp = arr[*baris][*kolom];
				for (int i = *kolom; i <= MAX_COLUMNS-1; i++)
				{
					if (i == MAX_COLUMNS-1){
						arr[*baris][i] = NULL;
					}else{
						arr[*baris][i] = arr[*baris][i+1];
					}
					
					gotoxy(*baris,i);
					
					if (arr[*baris][i] != NULL){
						printf("%c", arr[*baris][i]);
					}else{
						printf(" ");
					}
				}
			}
			
			*baris = *baris - 1;
			for (int i = 0; i <= MAX_COLUMNS-1; i++){
				if(arr[*baris][i] == NULL){
					*kolom = i;
					arr[*baris][*kolom] = temp;
					gotoxy(*baris,*kolom);
					printf("%c", arr[*baris][*kolom]);
					*kolom = *kolom;
					gotoxy(*baris,*kolom);
					break;
				}
				
				if (i == MAX_COLUMNS-1){	
					*kolom = i;
					arr[*baris][*kolom] = temp;
					gotoxy(*baris,*kolom);
					printf("%c", arr[*baris][*kolom]);
					*kolom = *kolom;
					gotoxy(*baris,*kolom);
				}
			}
			gotoxy(*baris,*kolom);
		}
	}
=======
		if (*kolom == 0 and *baris != 0 and arr[*baris+1][*kolom] == NULL)
		{
			brs = *baris - 1;
			klm = *kolom;
			while (klm <= MAX_COLUMNS-1)
			{
				if (arr[brs][klm] == NULL){
					break;
				}
				klm = klm + 1;
			}
			*kolom = klm;
			*baris = brs;
		}
	}

>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
	
	// Enter
	if (*ch == 13)
	{
		if (*baris < MAX_ROWS-1){
			*baris = *baris + 1;
			*kolom = 0;
		}
		gotoxy(*baris, *kolom);
	}
	
	// Arrow
	if (*ch == -32)
	{
		*ch = getch();
		
		switch(*ch)
		{
			// Up Arrow
			case 72:
			{
				if (*baris <= MAX_ROWS-1){
					if (*baris == 0){
						gotoxy(*baris,*kolom);
					}else
					
					if (*baris != 0){
						*baris = *baris - 1;
						
						if (arr[*baris][*kolom] != NULL and *kolom != MAX_COLUMNS){
							gotoxy(*baris,*kolom);
							
						}else{
							for(int i = 0; i <= MAX_COLUMNS; i++)
							{
								if (arr[*baris][i] == NULL){
									*kolom = i - 1;
									break;
								}
							}
							if (*kolom < MAX_COLUMNS){
								*kolom = *kolom + 1;
							}
							gotoxy(*baris,*kolom);
						}
					}
				}
				break;
			}
			
			// Down Arrow
			case 80:
			{
				if (*baris <= MAX_ROWS-1){
					if (*baris == MAX_ROWS-1){
						gotoxy(*baris,*kolom);
					}else
					
<<<<<<< HEAD
					if (*baris != MAX_ROWS and arr[*baris+1][0] != NULL){
=======
					if (*baris != MAX_ROWS and arr[*baris+1][0] != NULL)
					{
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
						*baris = *baris + 1;
						
						if (arr[*baris][*kolom] != NULL and *kolom != MAX_COLUMNS){
							gotoxy(*baris,*kolom);
<<<<<<< HEAD
							
=======
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
						}else{
							for(int i = 0; i <= MAX_COLUMNS; i++)
							{
								if (arr[*baris][i] == NULL){
									*kolom = i - 1;
									break;
								}
							}
							if (*kolom < MAX_COLUMNS){
								*kolom = *kolom + 1;
							}
							gotoxy(*baris,*kolom);
						}
<<<<<<< HEAD
=======
					}else
					
					if (arr[*baris+1][0] == NULL and *baris != MAX_ROWS)
					{	
						for(int i = *baris+1; i < MAX_ROWS; i++)
						{
							if (arr[i][0] != NULL){
								*baris = *baris + 1;
								*kolom = 0;
								gotoxy(*baris,*kolom);
								break;
							}
						}
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
					}
				}
				break;
			}
			
			// Left Arrow
			case 75:
			{
				if (*kolom <= MAX_COLUMNS)
				{
					if (*kolom == 0 and *baris == 0){
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom != 0){
						*kolom = *kolom - 1;
						gotoxy(*baris, *kolom);
					}else
					
					if (*kolom == 0 and *baris != 0){
						*baris = *baris - 1;
						for (int i = 0; i <= MAX_COLUMNS; i++)
						{
							if(arr[*baris][*kolom] == NULL){
								break;
							}
							*kolom = i + 1;
						}
						if (*kolom > MAX_COLUMNS){
							*kolom = *kolom - 1;
						}
						gotoxy(*baris,*kolom);
					}
				}
				break;
			}
			
			// Right Arrow
			case 77:
			{
				if (*kolom <= MAX_COLUMNS)
<<<<<<< HEAD
				{
					if (*kolom == 0 and *baris == 0 and arr[0][*kolom+1] == NULL){
						gotoxy(*baris,*kolom);
					}else
					
=======
				{	
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
					if (*kolom <= MAX_COLUMNS and arr[*baris][*kolom] != NULL and (*kolom + 1) <= MAX_COLUMNS){
						*kolom = *kolom + 1;
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom <= MAX_COLUMNS and arr[*baris+1][0] != NULL and (*baris + 1) < MAX_ROWS){
						*kolom = 0;
						*baris = *baris + 1;
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom == MAX_COLUMNS and *baris == MAX_ROWS){
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom != MAX_COLUMNS and arr[*baris][*kolom] != NULL){
						for(int i = 0; i < MAX_COLUMNS; i++){
							if (arr[*baris][*kolom] == NULL){
								break;
							}
							*kolom = i + 1;
						}
						gotoxy(*baris,*kolom);
<<<<<<< HEAD
					}
					
=======
					}else
					
					if (*kolom != MAX_COLUMNS and arr[*baris][*kolom] != NULL){
						for(int i = 0; i < MAX_COLUMNS; i++){
							if (arr[*baris][*kolom] == NULL){
								break;
							}
							*kolom = i + 1;
						}
						gotoxy(*baris,*kolom);
					}else
					
					if (*kolom == MAX_COLUMNS and *baris < MAX_ROWS){
						for(int i = *baris+1; i < MAX_ROWS; i++)
						{
							if (arr[i][0] != NULL){
								*baris = *baris + 1;
								*kolom = 0;
								gotoxy(*baris,*kolom);
								break;
							}
						}
					}	
>>>>>>> 9915021 (Versi 2 Input Handling & Kursor)
				}
				break;
			}
		}
	}
}