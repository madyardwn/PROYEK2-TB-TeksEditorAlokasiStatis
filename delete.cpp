#include <stdio.h>
#include <conio.h>
#include "stdlib.h"
#include "delete.h"

void delete_rows()
{
  FILE *fptr1, *fptr2;
  char file1[] = "file1.txt";
  char file2[] = "file2.txt";
  char curr;
  int del, line_number = 0;
  printf("Masukkan nomor baris yang akan dihapus : ");
  scanf("%d", &del);
  fptr1 = fopen(file1, "r");
  fptr2 = fopen(file2, "w");
  curr = getc(fptr1);
  if (curr != EOF)
  {
    line_number = 1;
  }
  while (1)
  {
    if (del != line_number)
      putc(curr, fptr2);
    curr = getc(fptr1);
    if (curr == '\n')
      line_number++;
    if (curr == EOF)
      break;
  }
  
  fclose(fptr1);
  fclose(fptr2);
}

/*prototype function*/
int destroy_file(char nama_file_temp[30]);

void delete_file(){
    char nama_file[30];
    bool status_file;
    printf("\t\tMasukkan nama file yang akan dihapus: ");
    scanf("%s", nama_file);
    status_file = destroy_file(nama_file);
    if (status_file == true){
        printf("File : %s berhasil dihapus\n", nama_file);
    } else  {
        printf("File : %s gagal dihapus atau file tidak ada di dalam direktori\n", nama_file);
    }
}

int destroy_file(char nama_file_temp[30]) {
    system("cls");
    if (remove(nama_file_temp) == 0) {
        return true;
    } else {
        return false;
    }
}
