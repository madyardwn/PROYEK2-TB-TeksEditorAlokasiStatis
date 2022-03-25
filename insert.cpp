#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "insert.h"

void Insert(char arr[MAX_ROWS][MAX_COLUMNS])
{
    system("cls");
    char ch;
    bool Validasi_Input;
    gotoxy(0,0);
    int baris = 0;
    int kolom = 0;
    
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
				}
			}
			gotoxy(*baris,*kolom);
		}else
			
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
					
					if (*baris != MAX_ROWS and arr[*baris+1][0] != NULL){
						*baris = *baris + 1;
						
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
				{
					if (*kolom == 0 and *baris == 0 and arr[0][*kolom+1] == NULL){
						gotoxy(*baris,*kolom);
					}else
					
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
					}
					
				}
				break;
			}
		}
	}
}