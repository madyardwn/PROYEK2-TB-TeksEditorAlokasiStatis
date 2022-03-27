#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "FileHandler.h"
#include "insert.h"

using namespace std;

bool txt_extension(char const *name)
{
    size_t len = strlen(name);
    return len > 4 && strcmp(name + len - 4, ".txt") == 0;
}

int ListFile()
{
	system("cls");
	int jumlah = 1;
	char cwd[PATH_MAX];
    struct dirent *d;
    DIR *dr;
    
    getcwd(cwd, sizeof(cwd));
    dr = opendir(cwd);
    if(dr!=NULL)
    {
        cout<<"Daftar File : " <<endl;
        for(d=readdir(dr); d!=NULL; d=readdir(dr))
        {
        	if(txt_extension(d->d_name)){
        		cout<<jumlah<<". "<<d->d_name<<endl;
        		jumlah++;
			}
        }
        closedir(dr);
    }
    else
	{
		cout<<"\nERROR: Folder tidak ditemukan!";
	}
    cout<<endl;
    cout<<endl;
    return 0;
}

void modify(char arr[MAX_ROWS][MAX_COLUMNS])
{
	FILE *file;
	int baris;
	int kolom;
	char ch;
	char pilihFile[25];
	
	printf("Pilih nama File yang ingin dibuka :");
	fflush(stdin);
    scanf("%s", pilihFile);
    strcat(pilihFile,".txt");
    
	baris = 0;
	kolom = 0;
	file = fopen(pilihFile, "r");
	while(!feof(file)){
		ch = fgetc(file);
		if (ch == 13){
			arr[baris][kolom] = ch;
    		baris++;
    		kolom = 0;
		}else{
			arr[baris][kolom] = ch;
			kolom++;
		}
	}
	arr[baris][kolom] = '\0';
	fclose(file);
	
	system("cls");
	for (baris = 0; baris <= MAX_ROWS-1; baris++)
	{
		for(kolom = 0; kolom <= MAX_COLUMNS-1; kolom++)
		{
			printf("%c",arr[baris][kolom]);
		}
		kolom = 0;
	}
	Insert(arr);
	saveToFile(arr);
	system("pause");
}

void saveToFile(char arr[MAX_ROWS][MAX_COLUMNS]){
	system("cls");
	char nama_file[25];
	char pilihan;
	FILE *file;
	int baris;
	int kolom;

	
	printf("Hasil Ketikkan :\n");
	for (baris = 0; baris <= MAX_ROWS-1; baris++)
	{
		for(kolom = 0; kolom <= MAX_COLUMNS-1; kolom++){
			printf("%c",arr[baris][kolom]);
		}
		printf("\n");
		kolom = 0;
	}
	
	gotoxy(MAX_ROWS+2, 0);
	printf("Tekan Ctrl + S untuk simpan ...");
	pilihan = getch();
	if (pilihan == 19){
		
		printf("\n\nMasukkan nama file :");
		scanf("%s", &nama_file);
		strcat(nama_file,".txt");
		
		file = fopen(nama_file, "w");
		for (baris = 0; baris <= MAX_ROWS-1; baris++)
		{
			for(kolom = 0; kolom <= MAX_COLUMNS-1; kolom++)
			{
				fprintf(file, "%c",arr[baris][kolom]);
			}
			fprintf(file, "%c", '\n');
			kolom = 0;
		}
		fclose(file);
	}
 }

/*prototype function*/
int remove_file(char nama_file_temp[30]) {
    system("cls");
    if (remove(nama_file_temp) == 0) {
        return true;
    } else {
        return false;
    }
}

void delete_file(){
    char nama_file[30];
    bool status_file;
    printf("Masukkan nama file yang akan dihapus: ");
    scanf("%s", nama_file);
    status_file = remove_file(nama_file);
    if (status_file == true){
        printf("SUCCESS : %s berhasil dihapus\n", nama_file);
    } else  {
        printf("ERROR : %s gagal dihapus\n", nama_file);
    }
}