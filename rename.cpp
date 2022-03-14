#include <stdio.h>

void rename_file()
{
    char old_name[100], new_name[100];

    /* Input nama file lama dan nama file baru */
    printf("Masukan nama file yang akan diubah : ");
    scanf("%s", old_name);

    printf("masukan nama file baru : ");
    scanf("%s", new_name);


    /* mengganti nama file lama menjadi nama file baru */
    if (rename(old_name, new_name) == 0)
    {
        printf("File berhasil diganti namanya.\n");
    }
    else
    {
        printf("Nama file tidak dapat dirunah. Silakan periksa file yang anda miliki.\n");
    }

}
