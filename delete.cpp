#include <stdio.h>
#include <conio.h>
#include "stdlib.h"
#include "del_rename.h"

/*prototype function*/
int remove_file(char nama_file_temp[30]);

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


